#include <iostream>

int main () {
    unsigned long long t, x, y;

    std::cin >> t;

    while (t--) {
        std::cin >> x >> y;

        if (x - y > 1) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

