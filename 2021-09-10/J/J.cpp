#include <iostream>
#include <string>

int main () {
    std::string a, b;

    while (std::cin >> a >> b) {
        if (a == b) {
            std::cout << a << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    }

    return 0;
}

