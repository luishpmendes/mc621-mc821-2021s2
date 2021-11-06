#include <iostream>

int main () {
    int r, d, n, x, y, cr, result;

    while (std::cin >> r >> d >> n) {
        result = 0;

        while (n--) {
            std::cin >> x >> y >> cr;

            if (x * x + y * y <= (r - cr) * (r - cr) && 2 * cr <= d && x * x + y * y >= (r - d + cr) * (r - d + cr)) {
                result++;
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
