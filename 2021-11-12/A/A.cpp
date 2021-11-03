#include <iostream>

int main () {
    unsigned t, n, m;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> m;

            if (n % m == 0) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
