#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main () {
    unsigned n, m, i, j;
    std::vector<std::string> v, vRev, l, r, c;
    std::vector<bool> used;
    std::string result;

    while (std::cin >> n >> m) {
        v.resize(n);

        for (std::string & s : v) {
            std::cin >> s;
        }

        vRev = v;

        for (std::string & s : vRev) {
            std::reverse(s.begin(), s.end());
        }

        used.clear();
        used.resize(n, false);

        l.clear();
        r.clear();

        for (i = 0; i < n; i++) {
            if (!used[i]) {
                for (j = i + 1; j < n; j++) {
                    if (!used[j] && v[i].compare(vRev[j]) == 0) {
                        l.push_back(v[i]);
                        r.push_back(v[j]);
                        used[i] = true;
                        used[j] = true;
                    }
                }
            }
        }

        c.clear();

        for (i = 0; i < n; i++) {
            if (!used[i] && v[i].compare(vRev[i]) == 0) {
                c.push_back(v[i]);
                used[i] = true;
                break;
            }
        }

        result = "";

        for (const std::string & s : l) {
            result += s;
        }

        for (const std::string & s : c) {
            result += s;
        }

        std::reverse(r.begin(), r.end());

        for (const std::string & s : r) {
            result += s;
        }

        std::cout << result.size() << std::endl
                  << result << std::endl;
    }

    return 0;
}

