#include <iostream>
#include <string>
#include <vector>

int main () {
    unsigned n, i, j;
    std::vector<std::string> patterns;
    std::string result;
    char c;
    bool arbitrary;

    while (std::cin >> n) {
        patterns.resize(n);

        for (std::string & s : patterns) {
            std::cin >> s;
        }

        result = "";

        for (j = 0; j < patterns.front().size(); j++) {
            c = patterns.front()[j];
            arbitrary = false;

            for (i = 1; i < n; i++) {
                if (c == '?') {
                    c = patterns[i][j];
                } else if (c != patterns[i][j] && patterns[i][j] != '?') {
                    arbitrary = true;
                    break;
                }
            }

            if (arbitrary) {
                result += '?';
            } else if (c == '?') {
                result += 'a';
            } else {
                result += c;
            }
        }

        std::cout << result << std::endl;
    }
}

