#include <iostream>

int main () {
    unsigned a, b,
             a2, a3, a5,
             b2, b3, b5,
             result;

    while (std::cin >> a >> b) {
        a2 = a3 = a5 = 0;
        b2 = b3 = b5 = 0;
        result = 0;

        while (a % 2 == 0) {
            a /= 2;
            a2++;
        }

        while (a % 3 == 0) {
            a /= 3;
            a3++;
        }

        while (a % 5 == 0) {
            a /= 5;
            a5++;
        }

        while (b % 2 == 0) {
            b /= 2;
            b2++;
        }

        while (b % 3 == 0) {
            b /= 3;
            b3++;
        }

        while (b % 5 == 0) {
            b /= 5;
            b5++;
        }

        if (a != b) {
            std::cout << -1 << std::endl;
        } else {
            if (a2 > b2) {
                result += a2 - b2;
            } else {
                result += b2 - a2;
            }

            if (a3 > b3) {
                result += a3 - b3;
            } else {
                result += b3 - a3;
            }

            if (a5 > b5) {
                result += a5 - b5;
            } else {
                result += b5 - a5;
            }

            std::cout << result << std::endl;
        }
    }

    return 0;
}
