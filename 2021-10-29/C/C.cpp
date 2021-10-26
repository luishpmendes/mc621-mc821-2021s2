#include <iostream>

int main () {
    unsigned n, i, j, a, q, result;

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    while (std::cin >> n) {
        result = 0;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                std::cin >> a;

                if (i == j) {
                    result ^= a;
                }
            }
        }

        std::cin >> q;

        while (q--) {
            std::cin >> a;

            if (a == 3) {
                std::cout << result;
            } else {
                std::cin >> a;
                result ^= 1;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
