#include <iostream>

int main () {
    unsigned t, n, k;

    std::cin >> t;

    while (t--) {
        std::cin >> n >> k;

        std::cout << (k - 1 + (n % 2) * (k - 1) / (n / 2)) % n + 1 << std::endl;
    }

    return 0;
}

