#include <algorithm>
#include <iostream>
#include <vector>

int main () {
    unsigned t, n, c1, c2, i;
    std::string a, b;
    std::vector<unsigned> ac, bc;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> a >> b;
            c1 = c2 = 0;
            ac.clear();
            bc.clear();

            for (i = 0; i < n - 1; i++) {
                if (a[i] != a[i + 1]) {
                    c1++;
                    ac.push_back(i + 1);
                }
            }


            for (i = 0; i < n - 1; i++) {
                if (b[i] != b[i + 1]) {
                    c2++;
                    bc.push_back(i + 1);
                }
            }

            if (a.back() == b.back()) {
                std::cout << c1 + c2 << ' ';
            } else {
                std::cout << c1 + c2 + 1 << ' ';
            }

            for (const unsigned & c : ac) {
                std::cout << c << ' ';
            }

            if (a.back() != b.back()) {
                std::cout << n << ' ';
            }

            std::reverse(bc.begin(), bc.end());


            for (const unsigned & c : bc) {
                std::cout << c << ' ';
            }

            std::cout << std::endl;
        }
    }

    return 0;
}

