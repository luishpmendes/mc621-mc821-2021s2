#include <iostream>
#include <vector>
#include <string>

int main () {
    unsigned n, i;
    std::vector<unsigned> p, v;
    std::vector<std::string> s;
    bool result;

    while (std::cin >> n) {
        p.resize(n);
        s.resize(n);
        v.clear();
        v.resize(n, 0);
        result = true;

        for (i = 0; i < n; i++) {
            std::cin >> p[i];
        }

        std::cin.ignore(1);

        for (i = 0; i < n; i++) {
            std::getline(std::cin, s[i]);
        }

        for (i = 0; i < n; i++) {
            for (const char & c : s[i]) {
                if (c == 'a' ||
                    c == 'e' ||
                    c == 'i' ||
                    c == 'o' ||
                    c == 'u' ||
                    c == 'y') {
                    v[i]++;
                }
            }

            if (p[i] != v[i]) {
                result = false;
                break;
            }
        }

        if (result) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

