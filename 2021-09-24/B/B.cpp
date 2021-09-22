#include <cmath>
#include <iostream>

int main () {
    unsigned t, a, b;

    std::cin >> t;

    while (t--) {
        std::cin >> a >> b;

        std::cout << ((unsigned) ceil(((double) a)/((double) b))) * b - a << std::endl;
    }

    return 0;
}

