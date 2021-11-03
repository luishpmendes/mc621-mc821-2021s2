#include <iostream>

int main () {
    unsigned t, n;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            if (n % 4 == 0) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
