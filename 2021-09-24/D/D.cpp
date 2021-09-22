#include <iostream>

int main () {
    unsigned n;

    while (std::cin >> n) {
        if (n == 1) {
            std::cout << 3 << std::endl;
        } else if (n == 2) {
            std::cout << 4 << std::endl;
        } else {
            std::cout << n - 2 << std::endl;
        }
    }

    return 0;
}

