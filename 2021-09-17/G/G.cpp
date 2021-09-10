#include <iostream>
#include <vector>

int main () {
    unsigned n, k, m, a, i;
    std::vector<std::vector<unsigned>> b;

    std::cin >> n >> k >> m;
    b.resize(m);

    while (n--) {
        std::cin >> a;
        b[a % m].push_back(a);
    }

    for (const auto & aux : b) {
        if (aux.size() >= k) {
            std::cout << "Yes" << std::endl;

            for (i = 0; i < k - 1; i++) {
                std::cout << aux[i] << ' ';
            }

            std::cout << aux[i] << std::endl;
            return 0;
        }
    }

    std::cout << "No" << std::endl;

    return 0;
}

