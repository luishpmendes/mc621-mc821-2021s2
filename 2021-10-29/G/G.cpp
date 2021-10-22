#include <iostream>

int main() {
    unsigned n, p, v, t, result;

    while (std::cin >> n) {
        result = 0;

        while (n--) {
            std::cin >> p >> v >> t;

            if (p + v + t >= 2) {
                result++;
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
