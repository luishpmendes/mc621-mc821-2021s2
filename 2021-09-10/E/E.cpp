#include <bitset>
#include <iostream>
#include <vector>

#define MAX_N 1010

void sieve (std::bitset<MAX_N> & bs, std::vector<unsigned> & primes) {
    unsigned i, j;

    bs.set();
    bs[0] = bs[1] = 0;

    for (i = 2; i < bs.size(); i++) {
        if (bs[i]) {
            for (j = i * i; j < bs.size(); j += i) {
                bs[j] = 0;
            }

            primes.push_back(i);
        }
    }
}

bool is_prime (unsigned n, std::bitset<MAX_N> & bs, std::vector<unsigned> & primes) {
    if (n < bs.size()) {
        return bs[n];
    }

    unsigned i;

    for (i = 0; i < primes.size(); i++) {
        if (n % primes[i] == 0) {
            return false;
        }
    }

    return true;
}

int main () {
    unsigned n, m, i;
    std::bitset<MAX_N> bs;
    std::vector<unsigned> primes;

    sieve(bs, primes);

    while (std::cin >> n) {
        m = n;

        while (!is_prime(m, bs, primes)) {
            m++;
        }

        std::cout << m << std::endl
                  << 1 << ' ' << n << std::endl;

        for (i = 1; i < n; i++) {
            std::cout << i << ' ' << i + 1 << std::endl;
        }

        for (i = 1; i + n <= m; i++) {
            std::cout << i << ' ' << i + n / 2 << std::endl;
        }
    }

    return 0;
}

