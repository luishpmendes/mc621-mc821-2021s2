#include <iostream>

int main () {
    unsigned long long n;

    while (std::cin >> n) {
        if (n & 1) {
            std::cout << 0 << std::endl;
        } else {
            if (n % 4 == 0) {
                std::cout << (n / 4) - 1 << std::endl;
            } else {
                std::cout << n / 4 << std::endl;
            }
        }
    }

    return 0;
}

