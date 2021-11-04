#include <cmath>
#include <iostream>

int main () {
    unsigned n, w, h;

    while (std::cin >> n) {
        w = ceil(sqrt((double) n));
        h = ceil((double) n / w);
        std::cout << 2 * (h + w) << std::endl;
    }

    return 0;
}
