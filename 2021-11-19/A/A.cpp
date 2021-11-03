#include <iostream>
#include <string>

int main () {
    unsigned  n,  m,
              i,  j,
             r1, c1,
             r2, c2,
             r3, c3,
             r4, c4;
    std::string s;

    while (std::cin >> n >> m) {
        r1 = c1 = r2 = c2 = r3 = c3 = r4 = c4 = 0;

        std::getline(std::cin, s);

        for (i = 0; i < n; i++) {
            std::getline(std::cin, s);

            for (j = 0; j < m; j++) {
                if (s[j] == '*') {
                    if (r1 == 0) {
                        r1 = i + 1;
                        c1 = j + 1;
                    } else if (r2 == 0) {
                        r2 = i + 1;
                        c2 = j + 1;
                    } else if (r3 == 0) {
                        r3 = i + 1;
                        c3 = j + 1;
                    }
                }
            }
        }

        if (r2 == r3) {
            r4 = r1;
        } else if (r1 == r3) {
            r4 = r2;
        } else if (r1 == r2) {
            r4 = r3;
        }

        if (c2 == c3) {
            c4 = c1;
        } else if (c1 == c3) {
            c4 = c2;
        } else if (c1 == c2) {
            c4 = c3;
        }

        std::cout << r4 << ' ' << c4 << std::endl;
    }
}
