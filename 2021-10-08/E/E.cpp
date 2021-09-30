#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main () {
    unsigned t, n, i;
    std::vector<std::string> v;
    bool consistent;

    std::cin >> t;

    while (t--) {
        std::cin >> n;
        v.resize(n);

        for (std::string & s : v) {
            std::cin >> s;
        }

        std::sort(v.begin(), v.end());
        consistent = true;

        for (i = 0; i < n - 1 && consistent; i++) {
            if (v[i].compare(v[i + 1].substr(0, v[i].size())) == 0) {
                consistent = false;
            }
        }

        if (consistent) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

