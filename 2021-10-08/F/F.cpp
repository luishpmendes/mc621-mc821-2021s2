#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main () {
    std::string s, p;
    std::vector<std::pair<unsigned, unsigned>> v;
    unsigned result, i;

    while (std::cin >> s >> p) {
        if (s.size() < p.size()) {
            std::cout << 0 << std::endl;
            continue;
        }

        v.clear();
        v.resize('z'-'a' + 10, std::make_pair(0, 0));
        result = 0;

        for (i = 0; i < p.size(); i++) {
            if (p[i] - 'a' >= 0 && p[i] - 'a' < (int) v.size()) {
                v[p[i] - 'a'].first++;
            }

            if (s[i] - 'a' >= 0 && s[i] - 'a' < (int) v.size()) {
                v[s[i] - 'a'].second++;
            }
        }

        if (std::all_of(v.begin(),
                        v.end(),
                        [](const std::pair<unsigned, unsigned> & x) {
                            return x.first >= x.second;
                        })) {
            result++;
        }

        for (; i < s.size(); i++) {
            if (s[i - p.size()] - 'a' >= 0 && s[i - p.size()] - 'a' < (int) v.size()) {
                v[s[i - p.size()] - 'a'].second--;
            }

            if (s[i] - 'a' >= 0 && s[i] - 'a' < (int) v.size()) {
                v[s[i] - 'a'].second++;
            }

            if (std::all_of(v.begin(),
                            v.end(),
                            [](const std::pair<unsigned, unsigned> & x) {
                                return x.first >= x.second;
                            })) {
                result++;
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}

