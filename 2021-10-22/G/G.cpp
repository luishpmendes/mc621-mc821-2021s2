#include <iostream>
#include <set>
#include <string>

int main () {
    unsigned n, m, i, both;
    std::string s;
    std::set<std::string> poland;

    std::cin.sync_with_stdio(0);
    std::cout.sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    while (std::cin >> n >> m) {
        poland.clear();

        for (i = 0; i < n; i++) {
            std::cin >> s;
            poland.insert(s);
        }

        both = 0;

        for (i = 0; i < m; i++) {
            std::cin >> s;
            both += poland.count(s);
        }

        if (n + (both & 1) > m) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

