#include <iostream>

int main () {
    unsigned long long t, n, i, a, s, k, result;

    std::cin >> t;

    while (t--) {
        std::cin >> n;

        s = 0;

        for (i = 0; i < n; i++) {
            std::cin >> a;
            s += a;
        }

        k = s % n;
        result = k * (n - k);

        std::cout << result << std::endl;
    }

    return 0;
}

