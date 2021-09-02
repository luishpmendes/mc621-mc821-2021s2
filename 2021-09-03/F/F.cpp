#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main () {
    unsigned n, i;
    std::vector<double> p;
    double P, S, delta, result;

    while (std::cin >> n) {
        p.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> p[i];
        }

        std::sort(p.begin(), p.end());

        P = 1.0 - p.back();
        S = p.back() / (1.0 - p.back());
        result = P * S;

        for (i = 1; i < n; i++) {
            delta = P * p[n - 1 - i] * (1.0 - S);

            if (delta > 0) {
                result += delta;
                P *= (1.0 - p[n - 1 - i]);
                S += p[n - 1 - i] / (1.0 - p[n - 1 - i]);
            } else {
                break;
            }
        }

        if (p.back() >= 1.0 - 1E-9) {
            result = p.back();
        }

        std::cout << std::fixed << std::setprecision(12) << result << std::endl;
    }
}

