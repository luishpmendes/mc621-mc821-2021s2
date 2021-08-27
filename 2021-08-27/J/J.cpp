#include <iostream>

typedef unsigned long long ull;

bool is_really_big_number(ull x, ull s) {
    ull copy = x,
        sum = 0;
    while (copy > 0) {
        sum += copy % 10;
        copy = copy / 10;
    }
    return (x - sum >= s);
}

int main () {
    ull n, s, y, l, r, m;
    bool b;
    while (std::cin >> n >> s) {
        l = 1;
        r = n;
        y = n + 1;
        while (l <= r) {
            m = (l + r) / 2;
            b = is_really_big_number(m, s);
            if (b) {
                r = m - 1;
                y = m;
            } else {
                l = m + 1;
            }
        }
        std::cout << (n - y + 1) << std::endl;
    }
    return 0;
}

