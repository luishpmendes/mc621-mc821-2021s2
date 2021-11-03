#include <iostream>

bool is_square(unsigned long long n) {
    unsigned long long left = 1,
                       right = n,
                       mid,
                       square;

    while (left <= right) {
        mid = (left + right) / 2;
        square = mid * mid;

        if (square == n) {
            return true;
        } else if (square < n) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main () {
    unsigned long long t, n;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;

            if ((n % 2 == 0 && is_square(n / 2)) || (n % 4 == 0 && is_square(n / 4))) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
