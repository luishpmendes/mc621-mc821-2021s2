#include <algorithm>
#include <iostream>
#include <vector>

int main () {
    unsigned long long n, m, type, l, r, i, result;
    std::vector<unsigned long long> v, u, dp1, dp2;

    while (std::cin >> n) {
        v.clear();
        u.clear();
        dp1.clear();
        dp2.clear();
        v.resize(n);
        u.resize(n);
        dp1.resize(n + 1, 0);
        dp2.resize(n + 1, 0);

        for (i = 0; i < n; i++) {
            std::cin >> v[i];

            dp1[i + 1] = dp1[i] + v[i];
        }

        u = v;

        std::sort(u.begin(), u.end());

        for (i = 0; i < n; i++) {
            dp2[i + 1] = dp2[i] + u[i];
        }

        std::cin >> m;

        while (m--) {
            std::cin >> type >> l >> r;
            l--;
            result = 0;

            if (type == 1) {
                result = dp1[r];

                if (l > 0) {
                    result -= dp1[l];
                }
            } else {
                result = dp2[r];

                if (l > 0) {
                    result -= dp2[l];
                }
            }

            std::cout << result << std::endl;
        }
    }

    return 0;
}
