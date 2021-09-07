#include <iostream>
#include <vector>

unsigned gcd (unsigned a, unsigned b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main () {
    unsigned n, i, prev, curr;
    std::vector<unsigned> a;
    while (std::cin >> n) {
        std::cin >> curr;
        a.push_back(curr);
        for (i = 1; i < n; i++) {
            prev = curr;
            std::cin >> curr;
            if (gcd(prev, curr) > 1) {
                a.push_back(1);
            }
            a.push_back(curr);
        }
        std::cout << a.size() - n << std::endl;
        for (i = 0; i < a.size() - 1; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << a.back() << std::endl;
    }

    return 0;
}

