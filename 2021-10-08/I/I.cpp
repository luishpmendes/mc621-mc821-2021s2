#include <iostream>
#include <string>

int main () {
    unsigned n, i;
    std::string s;
    bool diff;

    while (std::cin >> n >> s) {
        for (const std::string & t : {"vaporeon",
                                      "jolteon",
                                      "flareon",
                                      "espeon",
                                      "umbreon",
                                      "leafeon",
                                      "glaceon",
                                      "sylveon"}) {
            if (t.size() != n) {
                continue;
            }

            diff = false;

            for (i = 0; i < n && !diff; i++) {
                if (s[i] != '.' && s[i] != t[i]) {
                    diff = true;
                }
            }

            if (!diff) {
                std::cout << t << std::endl;
                break;
            }
        }
    }

    return 0;
}

