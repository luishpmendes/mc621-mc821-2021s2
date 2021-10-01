#include <iostream>

int main () {
    unsigned n, k, m, i, result;

    std::cin >> n;

    result = 0;

    for (k = 1; k <= n; k++) {
        m = n;
        for (i = 0; m; i++) {
            if (m > 2 * k) {
                m -= k;
            } else if (m > k) {
                m--;
            } else if (m > 1) {
                m = 1;
            } else {
                m = 0;
            }
        }
        if ((i & 1) == 0) {
            result++;
        }
    }

    std::cout << result << std::endl;

    return 0;
}

