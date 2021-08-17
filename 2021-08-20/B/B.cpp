#include <iostream>
#include <string>

int main () {
    std::string s, t;
    while (std::cin >> s >> t) {
        unsigned n = s.size(),
                 d = 0,
                 i,
                 j;
        for (i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                d++;
            }
        }
        if (d & 1) {
            std::cout << "impossible" << std::endl;
        } else {
            for (i = 0, j = 0; i < n && j < d/2; i++) {
                if (s[i] != t[i]) {
                    s[i] = t[i];
                    j++;
                }
            }
            std::cout << s << std::endl;
        }
    }
    return 0;
}

