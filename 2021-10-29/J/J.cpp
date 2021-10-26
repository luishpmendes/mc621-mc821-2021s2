#include <iostream>
#include <vector>

unsigned gcd (unsigned a, unsigned b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main () {
    unsigned n, i, d, max_a, result;
    std::vector<unsigned> a;

    while (std::cin >> n) {
        a.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        d = max_a = a[0];

        for (i = 1; i < n; i++) {
            d = gcd(d, a[i]);

            if (max_a < a[i]) {
                max_a = a[i];
            }
        }

        result = max_a / d - n;

        if (result & 1) {
            std::cout << "Alice" << std::endl;
        } else {
            std::cout << "Bob" << std::endl;
        }
    }

    return 0;
}
