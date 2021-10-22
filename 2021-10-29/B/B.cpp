#include <iostream>
#include <vector>

int main () {
    unsigned n, s, result;
    std::vector<unsigned> c;

    while (std::cin >> n) {
        c.clear();
        c.resize(5, 0);
        result = 0;

        while (n--) {
            std::cin >> s;
            c[s]++;
        }

        result += c[4];
        c[4] = 0;

        if (c[1] < c[3]) {
            result += c[1];
            c[3] -= c[1];
            c[1] = 0;
        } else {
            result += c[3];
            c[1] -= c[3];
            c[3] = 0;
        }

        if (c[1] && c[2]) {
            if (c[1] > 2 * c[2]) {
                result += c[2];
                c[1] -= 2 * c[2];
                c[2] = 0;
            } else {
                result += c[1] / 2;
                c[2] -= (c[1] + 1) / 2;
                c[1] %= 2;
            }
        }

        result += c[3];
        c[3] = 0;

        if (c[2]) {
            result += (c[2] + 1) / 2;
            c[2] %= 2;
        }

        if (c[1] > 0) {
            result += (c[1] + 3) / 4;
            c[1] = 0;
        }

        std::cout << result << std::endl;
    }

    return 0;
}
