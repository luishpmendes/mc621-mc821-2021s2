#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main () {
    unsigned n, m, i;
    std::vector<std::pair<std::string, unsigned>> v;

    while (std::cin >> n >> m) {
        v.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> v[i].first;
            v[i].second = i + 1;
        }

        std::sort(v.begin(),
                  v.end(),
                  [m](const std::pair<std::string, unsigned> & s,
                         const std::pair<std::string, unsigned> & t) {
                        for (unsigned i = 0; i < m; i++) {
                            if ((i & 1) == 0) {
                                if (s.first[i] < t.first[i]) {
                                    return true;
                                } else if (s.first[i] > t.first[i]) {
                                    return false;
                                }
                            } else {
                                if (s.first[i] < t.first[i]) {
                                    return false;
                                } else if (s.first[i] > t.first[i]) {
                                    return true;
                                }
                            }
                        }

                        return s.second < t.second;
                  });

        for (i = 0; i < n - 1; i++) {
            std::cout << v[i].second << ' ';
        }

        std::cout << v[i].second << std::endl;
    }

    return 0;
}

