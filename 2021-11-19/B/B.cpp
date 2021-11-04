#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

int main () {
    unsigned n, k, i;
    std::vector<double> x;
    std::vector<double> y;
    double result;

    while (std::cin >> n >> k) {
        x.resize(n);
        y.resize(n);
        result = 0.0;

        for (i = 0; i < n; i++) {
            std::cin >> x[i] >> y[i];
        }

        for (i = 1; i < n; i++) {
            result += k * sqrt((x[i] - x[i - 1]) * (x[i] - x[i - 1]) + (y[i] - y[i - 1]) * (y[i] - y[i - 1]));
        }

        result /= 50.0;

        std::cout << std::fixed << std::setprecision(9) << result << std::endl;
    }

    return 0;
}
