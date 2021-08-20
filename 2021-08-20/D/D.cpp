#include <iostream>

int main () {
    unsigned n, a;
    bool result;
    while (std::cin >> n) {
        result = false;
        while (n--) {
            std::cin >> a;
            if (a == 1) {
                result = true;
            }
        }
        if (result) {
            std::cout << "-1" << std::endl;
        } else {
            std::cout << "1" << std::endl;
        }
    }
    return 0;
}

