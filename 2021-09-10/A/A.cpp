#include <bitset>
#include <iostream>
#include <set>
#include <vector>

#define MAX_N 3030

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

std::set<unsigned> prime_factors (unsigned n, const std::vector<unsigned> & primes) {
    std::set<unsigned> factors;
    unsigned pf_idx = 0, pf = primes[pf_idx];

    while (n != 1 && pf * pf < n) {
        while (n % pf == 0) {
            n /= pf;
            factors.insert(pf);
        }

        pf_idx++;
        pf = primes[pf_idx];
    }

    if (n != 1) {
        factors.insert(n);
    }

    return factors;
}

int main () {
    unsigned n, i, result;
    std::bitset<MAX_N> bs;
    std::vector<unsigned> primes;

    sieve(bs, primes);

    while (std::cin >> n) {
        result = 0;

        for (i = 1; i <= n; i++) {
            if (prime_factors(i, primes).size() == 2) {
                result++;
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}

