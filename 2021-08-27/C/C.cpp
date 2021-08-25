#include <iostream>

int main() {
    unsigned long long l, r, i, n;
    while (std::cin >> l >> r) {
        std::cout << "YES" << std::endl;
        n = (r - l) / 2 + 1;
        for (i = 0; i < n; i++) {
            std::cout << l + 2 * i << " " << l + 2 * i + 1 << std::endl;
        }
    }
    return 0;
}

