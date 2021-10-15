#include <iostream>
#include <limits>
#include <string>
#include <vector>

long long f(unsigned i, const std::string & s, std::vector<long long> & dp) {
    if (i >= s.size()) {
        return 0;
    } else if (dp[i] != -1) {
        return dp[i];
    } else if (s[i] == '0') {
        dp[i] = f(i + 1, s, dp);
    } else {
        long long count = 0,
                  aux;

        dp[i] = 0;

        for (unsigned j = i; j < s.size(); j++) {
            count = 10 * count + (s[j] - '0');

            if (count > std::numeric_limits<int>::max()) {
                break;
            }

            aux = count + f(j + 1, s, dp);

            if (dp[i] < aux) {
                dp[i] = aux;
            }
        }
    }

    return dp[i];
}

int main () {
    unsigned n;
    std::string s;
    std::vector<long long> dp;

    while (std::cin >> n) {
        while (n--) {
            std::cin >> s;
            dp.clear();
            dp.resize(s.size(), -1);
            std::cout << f(0, s, dp) << std::endl;
        }
    }

    return 0;
}

