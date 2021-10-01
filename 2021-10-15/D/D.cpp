#include <iostream>
#include <string>

int main () {
    std::string s;
    unsigned i, j, k;
    bool palindrome;

    while (std::cin >> s) {
        palindrome = true;

        for (i = 0; i < s.size(); i++) {
            for (j = s.size(); j > i + 1; j--) {
                for (k = 0; 2 * k < j - i; k++) {
                    if (s[i + k] != s[j - 1 - k]) {
                        palindrome = false;
                        break;
                    }
                }

                if (!palindrome) {
                    break;
                }
            }

            if (!palindrome) {
                break;
            }
        }

        if (palindrome) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << j - i << std::endl;
        }
    }

    return 0;
}

