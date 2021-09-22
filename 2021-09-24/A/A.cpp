#include <iostream>

unsigned long long f (unsigned long long x,
                      unsigned long long n,
                      unsigned long long a,
                      unsigned long long b) {
    return ((((a % n) * ((x * x) % n)) % n) + b) % n;
}

unsigned long long floyd_cycle_finding (unsigned long long x0,
                                        unsigned long long n,
                                        unsigned long long a,
                                        unsigned long long b) {
    unsigned long long tortoise = f(x0, n, a, b),
                       hare = f(tortoise, n, a, b),
                       mu = 0,
                       lambda = 1;

    while (tortoise != hare) {
        tortoise = f(tortoise, n, a, b);
        hare = f(f(hare, n, a, b), n, a, b);
    }

    hare = x0;

    while (tortoise != hare) {
        tortoise = f(tortoise, n, a, b);
        hare = f(hare, n, a, b);
        mu++;
    }

    hare = f(tortoise, n, a, b);

    while (tortoise != hare) {
        hare = f(hare, n, a, b);
        lambda++;
    }

    return lambda;
}

int main () {
    unsigned long long n, a, b;

    while (std::cin >> n >> a >> b) {
        std::cout << n - floyd_cycle_finding(0, n, a, b) << std::endl;
    }

    return 0;
}

