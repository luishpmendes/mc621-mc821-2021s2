#include <iostream>
#include <utility>
#include <vector>

int main () {
    unsigned n, x, y, i, reward;
    std::vector<std::vector<unsigned>> m;
    std::vector<std::pair<unsigned, unsigned>> v;

    while (std::cin >> n) {
        reward = 0;
        m.clear();
        m.resize(2, std::vector<unsigned>(n, 0));
        v.clear();

        for (i = 0; i < 2 * n; i++) {
            std::cin >> x >> y;
            x--;
            y--;
            if (m[x][y]) {
                v.push_back();
            }
            m[x][y]++;
        }
    }

    return 0;
}

