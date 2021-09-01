#include <iostream>
#include <vector>

int main () {
    unsigned t, n, m, i, r, R;
    std::vector <unsigned> a;
    double p, result;

    std::cin >> t;

    while (t--) {
        std::cin >> n >> m;

        a.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        R = n;

        while (R > 0 && a[R - 1] == R) {
            R--;
        }

        result = 1.0;

        if (R == 0) {
            result = 0;
        }

        while (m--) {
            std::cin >> r >> p;

            if (r >= R) {
                result *= 1.0 - p;
            }
        }

        result = 1.0 - result;

        std::cout << result << std::endl;
    }

    return 0;
}

