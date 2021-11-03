#include <iostream>
#include <vector>

int main () {
    unsigned t, n, i;
    std::vector<unsigned> a;
    bool found;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            a.resize(n);

            for (i = 0; i < n; ++i) {
                std::cin >> a[i];
            }

            found = false;

            for (i = 0; i < n - 2; i++) {
                if (a[i] + a[i + 1] <= a[n - 1]) {
                    found = true;
                    break;
                }
            }

            if (found) {
                std::cout << i + 1 << ' ' << i + 2 << ' ' << n << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        }
    }

    return 0;
}
