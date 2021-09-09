#include <iostream>
#include <string>
#include <vector>

int main () {
    std::string s;
    bool result;
    std::vector<unsigned> c;
    std::vector<bool> f;
    unsigned i, j, k;

    while (std::cin >> s) {
        result = true;

        c.clear();
        c.resize('z' - 'a' + 1, 0);

        for (i = 0; i < s.size(); i++) {
            c[s[i] - 'a']++;
        }

        k = 0;

        for (i = 0; 'a' + i <= 'z'; i++) {
            if (c[k] < c[i]) {
                k = i;
            }
        }

        f.clear();
        f.resize(s.size() + 1, true);

        for (i = 2; i * i <= s.size(); i++) {
            if (f[i]) {
                for (j = i * i; j <= s.size(); j += i) {
                    f[j] = false;
                }
            }
        }

        f[1] = true;

        for (i = 2; i + i <= s.size(); i++) {
            f[i] = false;
        }

        for (i = 1; i <= s.size(); i++) {
            if (!f[i]) {
                if (c[k] == 0) {
                    result = false;
                    break;
                }

                s[i - 1] = 'a' + k;
                c[k]--;
            }
        }

        if (result) {
            k = 0;

            for (i = 1; i <= s.size(); i++) {
                if (f[i]) {
                    while (c[k] == 0) {
                        k++;
                    }
                    s[i - 1] = 'a' + k;
                    c[k]--;
                }
            }

            std::cout << "YES" << std::endl
                      << s << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

