#include <iostream>
#include <map>
#include <vector>

int main () {
    unsigned long long t, n, k, mx, result;
    std::vector<unsigned long long> a;
    std::map<unsigned long long, unsigned long long> cnt;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> k;
            a.resize(n);

            for (auto & it : a) {
                std::cin >> it;
            }

            cnt.clear();
            mx = 0;

            for (auto & it : a) {
                if (it % k == 0) {
                    continue;
                }

                cnt[k - it % k]++;
                mx = std::max(mx, cnt[k - it % k]);
            }

            result = 0;

            for (auto [key, value] : cnt) {
                if (value == mx) {
                    result = k * (value - 1) + key + 1;
                }
            }

            std::cout << result << std::endl;
        }
    }

    return 0;
}

