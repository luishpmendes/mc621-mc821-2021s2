#include <iostream>

int main() {
    unsigned long long n, m;
    while (std::cin >> n >> m) {
        if (n >= 30) {
            std::cout << m << std::endl;
        } else {
            unsigned long long mask = 1 << (n - 1);
            while (n--) {
                mask = mask | (mask >> 1);
            }
            m = m & mask;
            std::cout << m << std::endl;
        }
    }
    return 0;
}

