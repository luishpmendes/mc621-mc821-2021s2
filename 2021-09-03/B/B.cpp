#include <iostream>

int main () {
    unsigned n;
    double r;

    while (std::cin >> n) {
        r = 0.0;

        while (n > 0) {
            r += 1.0 / ((double) n);
            n--;
        }

        std::cout << r << std::endl;
    }

    return 0;
}

