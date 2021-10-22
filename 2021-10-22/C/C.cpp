#include <iostream>
#include <string>

int main () {
    int t, l, r, l2, r2, l3, r3;
    std::string s, result;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> s;

            l = 0;
            r = s.size() - 1;

            for (l = 0, r = s.size() - 1; l < r && s[l] == s[r]; l++, r--) {}

            for (l2 = l; l2 <= r; l2++) {
                for (l3 = l2, r3 = r; l3 <= r3 && s[l3] == s[r3]; l3++, r3--) {}

                if (l3 > r3) {
                    break;
                }
            }

            for (r2 = r; r2 >= l; r2--) {
                for (l3 = l, r3 = r2; l3 <= r3 && s[l3] == s[r3]; l3++, r3--) {}

                if (l3 > r3) {
                    break;
                }
            }

            result = s.substr(0, l);
            
            if (l + r > l2 + r2) {
                result += s.substr(l2, r - l2 + 1);
            } else {
                result += s.substr(l, r2 - l + 1);
            }

            result += s.substr(r + 1);

            std::cout << result << std::endl;
        }
    }

    return 0;
}

