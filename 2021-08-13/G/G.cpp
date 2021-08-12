#include <iostream>
#include <vector>

int main() {
    unsigned n;
    while (std::cin >> n) {
        std::vector<unsigned> a(n, 0);
        for (unsigned i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        unsigned m;
        std::cin >> m;
        std::vector<unsigned> b(m, 0);
        for (unsigned j = 0; j < m; j++) {
            std::cin >> b[j];
        }
        unsigned max_ratio = 0;
        for (unsigned i = 0; i < n; i++) {
            for (unsigned j = 0; j < m; j++) {
                if (b[j] % a[i] == 0) { // ratio is integer
                    unsigned ratio = b[j]/a[i];
                    if (max_ratio < ratio) {
                        max_ratio = ratio;
                    }
                }
            }
        }
        unsigned max_ratio_count = 0;
        for (unsigned i = 0; i < n; i++) {
            for (unsigned j = 0; j < m; j++) {
                if (b[j] % a[i] == 0) { // ratio is integer
                    unsigned ratio = b[j]/a[i];
                    if (ratio == max_ratio) {
                        max_ratio_count++;
                    }
                }
            }
        }
        std::cout << max_ratio_count << std::endl;
    }
    return 0;
}

