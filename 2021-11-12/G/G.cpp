#include <cmath>
#include <iomanip>
#include <iostream>

double degToRad(double deg) {
    return deg * M_PI / 180;
}

int main () {
    unsigned l, w, h, theta;
    double hprime, result;

    std::cout << std::fixed << std::setprecision(3);

    while (std::cin >> l >> w >> h >> theta) {
        hprime = tan(degToRad(theta)) * l;
        if (hprime <= h) {
            result = l * w * (h - hprime / 2);
        } else {
            result = w * h * h /(2 * tan(degToRad(theta)));
        }

        std::cout << result << " mL" << std::endl;
    }

    return 0;
}
