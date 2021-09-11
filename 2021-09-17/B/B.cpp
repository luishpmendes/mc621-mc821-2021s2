#include <bitset>
#include <iostream>
#include <set>
#include <vector>

#define MAX_N 10000000

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

std::set<unsigned> factors (unsigned n, const std::vector<unsigned> & primes) {
    std::set<unsigned> result, new_factors;
    unsigned pf_idx = 0, pf = primes[pf_idx];

    while (n != 1 && pf * pf <= n) {
        while (n % pf == 0) {
            n /= pf;
            new_factors.clear();
            new_factors.insert(pf);

            for (const auto & f : result) {
                new_factors.insert(f * pf);
            }

            for (const auto & f : new_factors) {
                result.insert(f);
            }
        }

        pf_idx++;
        pf = primes[pf_idx];
    }

    if (n != 1) {
        new_factors.clear();
        new_factors.insert(n);

        for (const auto & f : result) {
            new_factors.insert(f * n);
        }

        for (const auto & f : new_factors) {
            result.insert(f);
        }
    }

    return result;
}

int main () {
    unsigned a, b, result;
    std::bitset<MAX_N> bs;
    std::vector<unsigned> primes;
    std::set<unsigned> f;

    sieve(bs, primes);

    while (std::cin >> a >> b) {
        if (a < b) {
            std::cout << 0 << std::endl;
        } else if (a == b) {
            std::cout << "infinity" << std::endl;
        } else { // a > b
            result = 0;
            f = factors(a - b, primes);
            f.insert(1);

            for (const auto & i : f) {
                if (i > b) {
                    result++;
                }
            }

            std::cout << result << std::endl;
        }
    }

    return 0;
}

