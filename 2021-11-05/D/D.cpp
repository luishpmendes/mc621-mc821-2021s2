#include <iostream>
#include <set>
#include <vector>

int main () {
    unsigned t, n, i, j;
    std::vector<unsigned> x;
    std::set<double> s;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            x.resize(n);

            for (i = 0; i < n; i++) {
                std::cin >> x[i];
            }

            s.clear();

            for (i = 0; i < n; i++) {
                for (j = i + 1; j < n; j++) {
                    s.insert(((double) (x[j] - x[i])) / 2.0);
                }
            }

            std::cout << s.size() << std::endl;
        }
    }

    return 0;
}
