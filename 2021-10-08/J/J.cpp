#include <iostream>
#include <string>

int main () {
    unsigned n, m, wildcard_index;
    std::string s, t;

    while (std::cin >> n >> m >> s >> t) {
        for (wildcard_index = 0; wildcard_index < n; wildcard_index++) {
            if (s[wildcard_index] == '*') {
                break;
            }
        }

        if (wildcard_index >= n) {
            if (s.compare(t)) {
                std::cout << "NO" << std::endl;
            } else {
                std::cout << "YES" << std::endl;
            }
        } else if (n > m + 1) {
            std::cout << "NO" << std::endl;
        } else {
            if (s.substr(0, wildcard_index).compare(t.substr(0, wildcard_index)) || s.substr(wildcard_index + 1).compare(t.substr(m + 1 - (n - wildcard_index)))) {
                std::cout << "NO" << std::endl;
            } else {
                std::cout << "YES" << std::endl;
            }
        }
    }

    return 0;
}

