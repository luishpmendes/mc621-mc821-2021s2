#include <iostream>
#include <iomanip>
#include <string>
#include <tuple>
#include <vector>

void print_result(const std::vector<std::vector<unsigned>> & dp,
                  unsigned i,
                  unsigned j,
                  unsigned & offset,
                  unsigned & steps,
                  const std::string & s,
                  const std::string & t) {
    if (i == 0 && j == 0) {
        return;
    }

    if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) {
        print_result(dp, i - 1, j - 1, offset, steps, s, t);
    } else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
        print_result(dp, i, j - 1, offset, steps, s, t);
        offset++;
        steps++;
        std::cout << steps << " Insert " << i + offset << "," << t[j - 1] << std::endl;
    } else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
        print_result(dp, i - 1, j, offset, steps, s, t);
        steps++;
        std::cout << steps << " Delete " << i + offset << std::endl;
        offset--;
    } else if (dp[i][j] == dp[i - 1][j - 1] + 1) {
        print_result(dp, i - 1, j - 1, offset, steps, s, t);
        steps++;
        std::cout << steps << " Replace " << i + offset << "," << t[j - 1] << std::endl;
    }
}

int main () {
    std::string s, t;
    unsigned i, j, offset, steps;
    std::vector<std::vector<unsigned>> dp;
    bool flag = false;

    while (std::getline(std::cin, s)) {
        if (flag) {
            std::cout << std::endl;
        }

        flag = true;
        std::getline(std::cin, t);

        dp.clear();
        dp.resize(s.size() + 1, std::vector<unsigned>(t.size() + 1, 0));

        for (i = 0; i <= s.size(); i++) {
            dp[i][0] = i;
        }

        for (j = 0; j <= t.size(); j++) {
            dp[0][j] = j;
        }

        for (i = 0; i < s.size(); i++) {
            for (j = 0; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = dp[i][j] + 1; // edit

                    if (dp[i + 1][j + 1] > dp[i][j + 1] + 1) {
                        dp[i + 1][j + 1] = dp[i][j + 1] + 1; // delete a[i + 1]
                    }

                    if (dp[i + 1][j + 1] > dp[i + 1][j] + 1) {
                        dp[i + 1][j + 1] = dp[i + 1][j] + 1; // insert b[j + 1]
                    }
                }
            }
        }

        std::cout << dp[s.size()][t.size()] << std::endl;
        offset = steps = 0;
        print_result(dp, s.size(), t.size(), offset, steps, s, t);

    }


    return 0;
}

