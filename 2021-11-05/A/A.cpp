#include <iostream>
#include <vector>

int main () {
    unsigned t, n, k, i, j, dist;
    std::vector<unsigned> x, y;
    int result;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> k;
            x.resize(n);
            y.resize(n);
            result = -1;

            for (i = 0; i < n; i++) {
                std::cin >> x[i] >> y[i];
            }

            for (i = 0; i < n; i++) {
                dist = 0;

                for (j = 0; j < n; j++) {
                    if (dist < (x[i] >= x[j] ? x[i] - x[j] : x[j] - x[i]) + (y[i] >= y[j] ? y[i] - y[j] : y[j] - y[i])) {
                        dist = (x[i] >= x[j] ? x[i] - x[j] : x[j] - x[i]) + (y[i] >= y[j] ? y[i] - y[j] : y[j] - y[i]);
                    }
                }
                if (dist <= k) {
                    result = 1;
                }
            }

            std::cout << result << std::endl;
        }
    }

    return 0;
}
