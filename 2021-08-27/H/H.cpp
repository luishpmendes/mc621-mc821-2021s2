#include <algorithm>
#include <iostream>

#define MAXDIGITS 550     /* maximum length bignum */

#define PLUS 1              /* positive sign bit */
#define MINUS -1            /* negative sign bit */

typedef struct {
    char digits[MAXDIGITS]; /* represent the number */
    int signbit;            /* PLUS or MINUS */
    int lastdigit;          /* index of high-order digit */
} bignum;

void string_to_bignum (std::string s, bignum *n);
void initialize_bignum (bignum *n);
void print_bignum (bignum *n);
void zero_justify (bignum *n);
int compare_bignum (bignum *a, bignum *b);
void add_bignum (bignum *a, bignum *b, bignum *c);
void subtract_bignum (bignum *a, bignum *b, bignum *c);
void digit_shift (bignum *n, int d);
void multiply_bignum (bignum *a, bignum *b, bignum *c);

void initialize_bignum (bignum *n) {
    n->signbit = PLUS;
    n->lastdigit = 0;
    for (unsigned i = 0; i < MAXDIGITS; i++) {
        n->digits[i] = (char) 0;
    }
}

void string_to_bignum (std::string s, bignum *n) {
    unsigned i; /* counter */

    initialize_bignum(n);

    if (s.front() == '-') {
        n->signbit = MINUS;
    } else {
        n->signbit = PLUS;
    }

    for (i = 0; i < MAXDIGITS; i++) {
        n->digits[i] = (char) 0;
    }

    n->lastdigit = -1;

    for (i = 0; i < s.size(); i++) {
        n->lastdigit++;
        n->digits[n->lastdigit] = (char) (s[s.size() - 1 - i] - '0');
    }
}

void print_bignum (bignum *n) {
    int i;

    if (n->signbit == MINUS) {
        std::cout << "-";
    }

    for (i = n->lastdigit; i >= 0; i--) {
        std::cout << char('0' + n->digits[i]);
    }

    std::cout << std::endl;
}

void zero_justify (bignum *n) {
    while ((n->lastdigit > 0) && (n->digits[n->lastdigit] == 0)) {
        n->lastdigit --;
    }

    if ((n->lastdigit == 0) && (n->digits[0] == 0)) {
        n->signbit = PLUS; /* hack to avoid -0 */
    }
}

int compare_bignum (bignum *a, bignum *b) {
    int i; /* counter */
    if ((a->signbit == MINUS) && (b->signbit == PLUS)) {
        return(PLUS);
    }
    if ((a->signbit == PLUS) && (b->signbit == MINUS)) {
        return(MINUS);
    }

    if (b->lastdigit > a->lastdigit) {
        return (PLUS * a->signbit);
    }
    if (a->lastdigit > b->lastdigit) {
        return (MINUS * a->signbit);
    }

    for (i = a->lastdigit; i >= 0; i--) {
        if (a->digits[i] > b->digits[i]) {
            return (MINUS * a->signbit);
        }
        if (b->digits[i] > a->digits[i]) {
            return (PLUS * a->signbit);
        }
    }
    return (0);
}

void add_bignum (bignum *a, bignum *b, bignum *c) {
    int carry; /* carry digit */
    int i;     /* counter */

    initialize_bignum(c);

    if (a->signbit == b->signbit) {
        c->signbit = a->signbit;
    } else {
        if (a->signbit == MINUS) {
            a->signbit = PLUS;
            subtract_bignum(b,a,c);
            a->signbit = MINUS;
        } else {
            b->signbit = PLUS;
            subtract_bignum(a,b,c);
            b->signbit = MINUS;
        }
        return;
    }

    c->lastdigit = std::max(a->lastdigit, b->lastdigit)+1;
    carry = 0;

    for (i = 0; i <= c->lastdigit; i++) {
        c->digits[i] = (char) (carry + a->digits[i] + b->digits[i]) % 10;
        carry = (carry + a->digits[i] + b->digits[i]) / 10;
    }

    zero_justify(c);
}

void subtract_bignum (bignum *a, bignum *b, bignum *c) {
    int borrow; /* anything borrowed? */
    int v;      /* placeholder digit */
    int i;      /* counter */

    initialize_bignum(c);

    if ((a->signbit == MINUS) || (b->signbit == MINUS)) {
        b->signbit = -1 * b->signbit;
        add_bignum(a, b, c);
        b->signbit = -1 * b->signbit;
        return;
    }

    if (compare_bignum(a, b) == PLUS) {
        subtract_bignum(b, a, c);
        c->signbit = MINUS;
        return;
    }

    c->lastdigit = std::max(a->lastdigit, b->lastdigit);
    borrow = 0;

    for (i = 0; i <= c->lastdigit; i++) {
        v = (a->digits[i] - borrow - b->digits[i]);
        if (a->digits[i] > 0) {
            borrow = 0;
        }
        if (v < 0) {
            v = v + 10;
            borrow = 1;
        }

        c->digits[i] = (char) v % 10;
    }

    zero_justify(c);
}

/* multiply n by 10ˆd */
void digit_shift (bignum *n, int d) {
    int i; /* counter */

    if ((n->lastdigit == 0) && (n->digits[0] == 0)) {
        return;
    }

    for (i = n->lastdigit; i >= 0; i--) {
        n->digits[i + d] = n->digits[i];
    }

    for (i = 0; i < d; i++){
        n->digits[i] = 0;
    }
    
    n->lastdigit = n->lastdigit + d;
}

void multiply_bignum (bignum *a, bignum *b, bignum *c) {
    bignum row; /* represent shifted row */
    bignum tmp; /* placeholder bignum */
    int i, j;   /* counters */


    initialize_bignum(c);
    initialize_bignum(&row);
    initialize_bignum(&tmp);

    row = *a;

    for (i = 0; i <= b->lastdigit; i++) {
        for (j = 1; j <= b->digits[i]; j++) {
            add_bignum(c, &row, &tmp);
            *c = tmp;
        }
        digit_shift(&row, 1);
    }

    c->signbit = a->signbit * b->signbit;

    zero_justify(c);
}

int main () {
    std::string s1, s2;
    bignum n1, n2, p;

    while (std::cin >> s1 >> s2) {
        initialize_bignum(&n1);
        initialize_bignum(&n2);
        initialize_bignum(&p);
        string_to_bignum(s1, &n1);
        string_to_bignum(s2, &n2);
        multiply_bignum(&n1, &n2, &p);
        print_bignum(&p);
    }

    return 0;
}

