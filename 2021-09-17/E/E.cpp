#include <bitset>
#include <iostream>
#include <vector>

#define MAX_N 100100

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

std::vector<unsigned> prime_factors (unsigned n, const std::vector<unsigned> & primes) {
    std::vector<unsigned> factors;
    unsigned pf_idx = 0, pf = primes[pf_idx];

    while (n != 1 && pf * pf <= n) {
        while (n % pf == 0) {
            n /= pf;
            factors.push_back(pf);
        }

        pf_idx++;
        pf = primes[pf_idx];
    }

    if (n != 1) {
        factors.push_back(n);
    }

    return factors;
}

int main () {
    unsigned n, k, i;
    std::bitset<MAX_N> bs;
    std::vector<unsigned> primes;
    std::vector<unsigned> factors;

    sieve(bs, primes);

    while (std::cin >> n >> k) {
        factors = prime_factors(n, primes);

        if (factors.size() < k) {
            std::cout << -1 << std::endl;
        } else {
            while (factors.size() > k) {
                factors[factors.size() - 2] *= factors[factors.size() - 1];
                factors.pop_back();
            }

            for (i = 0; i < k - 1; i++) {
                std::cout << factors[i] << ' ';
            }

            std::cout << factors[i] << std::endl;
        }
    }

    return 0;
}

