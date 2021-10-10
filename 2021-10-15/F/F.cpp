#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define MOD 1000000007

unsigned long long pot(unsigned long long x, unsigned long long p) {
    if (p == 0) {
        return 1;
    }

    unsigned long long aux = pot(x, p >> 1);

    if ((p & 1) == 1) {
        return (((x * aux) % MOD) * aux) % MOD;
    } else {
        return (aux * aux) % MOD;
    }
}

int main () {
    unsigned long long n, k, i;
    std::string s;
    std::map<char, unsigned long long> dict;
    std::vector<unsigned long long> v;

    while (std::cin >> n >> s) {
        dict.clear();
        dict['A'] = 0;
        dict['C'] = 1;
        dict['G'] = 2;
        dict['T'] = 3;
        v.clear();
        v.resize(4, 0);

        for (const char & c : s) {
            v[dict[c]]++;
        }

        std::sort(v.rbegin(), v.rend());
        k = 0;

        for (i = 0; i < 4; i++) {
            k++;

            if (v[i] != v[i + 1]) {
                break;
            }
        }

        std::cout << pot(k, n) << std::endl;
    }

    return 0;
}

