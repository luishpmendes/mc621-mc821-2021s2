#include <iostream>

int main () {
    unsigned t, a;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> a;
            if (360 % (180-a) == 0) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
