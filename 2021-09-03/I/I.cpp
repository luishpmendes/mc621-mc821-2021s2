#include <iomanip>
#include <iostream>

int main () {
    unsigned n, i;
    double p, aux, result;
    while (std::cin >> n) {
        aux = result = 0.0;
        for (i = 0; i < n; i++) {
            std::cin >> p;
            result += (2.0 * aux + 1.0) * p;
            aux = (aux + 1.0) * p;
        }
        std::cout << std::fixed << std::setprecision(15) << result << std::endl;
    }
    return 0;
}

