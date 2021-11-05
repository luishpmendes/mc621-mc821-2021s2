#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

int main () {
    unsigned long long t, n, i, x_size, y_size;
    long long x, y;
    std::vector<unsigned long long> xs, ys;
    double result;

    std::cout << std::fixed << std::setprecision(15);

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            xs.resize(n);
            ys.resize(n);
            x_size = y_size = 0;
            result = 0.0;

            for (i = 0; i < 2 * n; i++) {
                std::cin >> x >> y;

                if (x == 0) {
                    ys[y_size++] = std::abs(y);
                } else if (y == 0) {
                    xs[x_size++] = std::abs(x);
                }
            }

            std::sort(xs.begin(), xs.end());
            std::sort(ys.begin(), ys.end());

            for (i = 0; i < n; i++) {
                result += sqrt(xs[i] * xs[i] + ys[i] * ys[i]);
            }

            std::cout << result << std::endl;
        }
    }

    return 0;
}
