#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main () {
    unsigned m, n, region, i;
    std::vector<int> h, hprime;
    double v, sum, water_level, region_under_water;

    region = 0;

    std::cout << std::fixed << std::setprecision(2);

    while (std::cin >> m >> n && m && n) {
        h.resize(m * n);
        hprime.resize(m * n);
        region++;

        for (i = 0; i < m * n; i++) {
            std::cin >> h[i];
        }

        std::cin >> v;
        v /= 100.00;
        std::sort(h.begin(), h.end());

        hprime[0] = 0;

        for (i = 1; i < m * n; i++) {
            hprime[i] = h[i] - h[i - 1];
        }

        sum = 0.00;

        for (i = 0; i < m * n; i++) {
            if (sum + i * hprime[i] < v) {
                sum += i * hprime[i];
            } else {
                break;
            }
        }

        water_level = h[i - 1] + (v - sum) / i;
        region_under_water = (double) i / (m * n) * 100.00;

        std::cout << "Region " << region << std::endl
                  << "Water level is " << water_level << " meters." << std::endl
                  << region_under_water << " percent of the region is under water." << std::endl
                  << std::endl;
    }

    return 0;
}
