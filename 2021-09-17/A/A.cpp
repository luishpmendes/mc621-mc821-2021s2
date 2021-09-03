#include <iostream>

int main () {
    unsigned long long t, n;
    std::cin >> t;

    while (t--) {
        std::cin >> n;

        if (n & (n - 1)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

