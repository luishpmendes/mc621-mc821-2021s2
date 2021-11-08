#include <cmath>
#include <iostream>

int main () {
    int x, y, s;
    double r;
    bool result;

    while (std::cin >> x >> y) {
        result = false;

        if (x != 0 && y != 0) {
            r = sqrt(x * x + y * y);
            s = (int) r;

            if (r != s) {
                if ((x < 0 && y < 0) || (x > 0 && y > 0)) {
                    if ((s & 1) == 1) {
                        result = true;
                    }
                } else {
                    if ((s & 1) == 0) {
                        result = true;
                    }
                }
            }
        }

        if (!result) {
            std::cout << "black" << std::endl;
        } else {
            std::cout << "white" << std::endl;
        }
    }

    return 0;
}
