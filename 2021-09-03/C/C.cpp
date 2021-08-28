#include <iostream>

int main () {
    int n, w, a, b, minB, maxB, result;

    while (std::cin >> n >> w) {
        b = minB = maxB = 0;

        while (n--) {
            std::cin >> a;

            b += a;

            if (minB > b) {
                minB = b;
            }

            if (maxB < b) {
                maxB = b;
            }
        }

        result = w - maxB + minB + 1;

        if (maxB > w || minB < -w || result > w + 1 || result < 0) {
            result = 0;
        }

        std::cout << result << std::endl;
    }

    return 0;
}

