#include <iostream>

int main () {
    unsigned n, a, b, result;

    while (std::cin >> n) {
        while (n--) {
            result = 0;
            std::cin >> a >> b;

            while (a && b) {
                if (a <= b) {
                    result += b / a;
                    b %= a;
                } else {
                    result += a / b;
                    a %= b;
                }
            }

            std::cout << result << std::endl;
        }
    }

    return 0;
}

