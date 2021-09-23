#include <iostream>
#include <vector>

int main () {
    unsigned n, i;
    std::vector<unsigned> a, b, c;
    std::vector<std::vector<unsigned long long>> dp;

    while (std::cin >> n) {
        a.resize(n);
        b.resize(n);
        c.resize(n);
        dp.resize(n, std::vector<unsigned long long> (2));

        for (i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for (i = 0; i < n; i++) {
            std::cin >> b[i];
        }

        for (i = 0; i < n; i++) {
            std::cin >> c[i];
        }

        dp.back().front() = a.back();
        dp.back().back() = b.back();

        for (i = n - 1; i > 0; i--) {
            dp[i - 1].front() = a[i - 1] + dp[i].back();
            if (dp[i - 1].front() < b[i - 1] + dp[i].front()) {
                dp[i - 1].front() = b[i - 1] + dp[i].front();
            }

            dp[i - 1].back() = b[i - 1] + dp[i].back();
            if (dp[i - 1].back() < c[i - 1] + dp[i].front()) {
                dp[i - 1].back() = c[i - 1] + dp[i].front();
            }
        }

        std::cout << dp.front().front() << std::endl;
    }

    return 0;
}

