#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main () {
    unsigned n;
    while (std::cin >> n) {
        std::vector<unsigned> next_next(3*1e6, 0);
        std::vector<std::pair<unsigned, unsigned>> v (n);
        std::vector<unsigned> a(n, 0), b(n, 0), c(n, 0);
        std::vector<unsigned> x(n, 0);
        for (unsigned i = 0; i < n; i++) {
            std::cin >> v[i].first >> v[i].second;
            a[i] = v[i].first;
            b[i] = v[i].second;
            next_next[a[i]] = b[i];
            if (v[i].first == 0) {
                x[1] = v[i].second;
            }
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::set_difference(a.begin(), a.end(), b.begin(), b.end(), c.begin());
        x[0] = c[0];
        for(unsigned i = 2; i < n; i++) {
            x[i] = next_next[x[i - 2]];
        }
        for (unsigned i = 0; i < n - 1; i++) {
            std::cout << x[i] << " ";
        }
        std::cout << x[n - 1] << std::endl;
    }
    return 0;
}

