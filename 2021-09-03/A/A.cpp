#include <iostream>
#include <string>

int main () {
    unsigned t, nr, nb, n, i;
    std::string r, b;

    std::cin >> t;

    while (t--) {
        std::cin >> n >> r >> b;

        nr = nb = 0;

        for (i = 0; i < n; i++) {
            if (r[i] > b[i]) {
                nr++;
            } else if (r[i] < b[i]) {
                nb++;
            }
        }

        if (nr > nb) {
            std::cout << "RED" << std::endl;
        } else if (nr < nb) {
            std::cout << "BLUE" << std::endl;
        } else {
            std::cout << "EQUAL" << std::endl;
        }
    }
    return 0;
}

