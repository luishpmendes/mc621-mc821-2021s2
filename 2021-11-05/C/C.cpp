#include <algorithm>
#include <iostream>
#include <vector>

int main () {
    unsigned long long t, n, i, result_x, result_y;
    std::vector<unsigned long long> x, y;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            x.resize(n);
            y.resize(n);

            for (i = 0; i < n; i++) {
                std::cin >> x[i] >> y[i];
            }

            std::nth_element(x.begin(), x.begin() + n / 2, x.end());
            result_x = x[n / 2];
            std::nth_element(x.begin(), x.begin() + (n - 1) / 2, x.end());
            result_x += 1 - x[(n - 1) / 2];
            
            std::nth_element(y.begin(), y.begin() + n / 2, y.end());
            result_y = y[n / 2];
            std::nth_element(y.begin(), y.begin() + (n - 1) / 2, y.end());
            result_y += 1 - y[(n - 1) / 2];
            

            std::cout << result_x * result_y << std::endl;
        }
    }

    return 0;
}
