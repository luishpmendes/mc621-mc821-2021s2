#include <iostream>

int main () {
    unsigned long long k, n, x, t, result;

    while (std::cin >> k) {
        while (k--) {
            std::cin >> n >> x >> t;

            if(t > (n - 1) * x) {
                result = (n * (n - 1)) / 2;
            } else {
                result = (n - (t / x)) * (t / x) + ((n - (n - (t / x)) - 1) * (n - (n - (t / x))))/2;
            }

            std::cout << result << std::endl;
        }
    }

    return 0;
}
