#include <iostream>
#include <vector>

int main () {
    unsigned t, n, i, a;
    std::vector<unsigned> even_indexes, odd_indexes;
    while (std::cin >> t) {
        while (t--) {
            even_indexes.clear();
            odd_indexes.clear();
            std::cin >> n;
            for (i = 1; i <= 2 * n; i++) {
                std::cin >> a;
                if (a & 1) {
                    odd_indexes.push_back(i);
                } else {
                    even_indexes.push_back(i);
                }
            }
            if (odd_indexes.size() & 1) {
                odd_indexes.pop_back();
            }
            if (even_indexes.size() & 1) {
                even_indexes.pop_back();
            }
            odd_indexes.insert(odd_indexes.end(),
                               even_indexes.begin(),
                               even_indexes.end());
            for (i = 0; i < 2 * n - 2; i += 2) {
                std::cout << odd_indexes[i] << " "
                          << odd_indexes[i + 1] << std::endl;
            }
        }
    }
}

