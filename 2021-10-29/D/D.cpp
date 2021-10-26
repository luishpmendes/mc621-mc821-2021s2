#include <iostream>

int main () {
    unsigned n, m;

    while (std::cin >> n >> m) {
        std::cout << ((n * m) >> 1) << std::endl;
    }

    return 0;
}
