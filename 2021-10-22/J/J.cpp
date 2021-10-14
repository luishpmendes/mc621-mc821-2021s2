#include <iostream>

int main () {
    unsigned short n, i, j;
    std::string s;

    while (std::cin >> n >> s) {
        for (i = 0; i < n; i++) {
            if (s[i] == 'o' && i + 2 < n) {
                j = i + 1;

                while (j + 1 < n && s[j] == 'g' && s[j + 1] == 'o') {
                    j += 2;
                }

                if (j > i + 1) {
                    std::cout << "***";
                    i = j - 1;
                    continue;
                }
            }

            std::cout << s[i];
        }

        std::cout << std::endl;
    }

    return 0;
}

