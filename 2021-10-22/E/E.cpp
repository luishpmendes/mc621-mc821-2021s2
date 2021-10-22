#include <iostream>
#include <map>
#include <vector>
#include <string>

int main () {
    std::string s, t;
    std::map<std::string, unsigned> suffix_map;
    std::vector<unsigned> suffix_array;
    unsigned i;

    while (std::cin >> s) {
        suffix_map.clear();
        suffix_array.clear();
        suffix_array.resize(s.size(), 0);

        t = "";
        for (i = s.size(); i > 0; i--) {
            t = s[i - 1] + t;
            suffix_map[t] = i - 1;
        }

        i = 0;
        for (const auto & x : suffix_map) {
            suffix_array[i] = x.second;
            i++;
        }

        for (i = 0; i < suffix_array.size(); i++) {
            std::cout << suffix_array[i] << std::endl;
        }
    }

    return 0;
}

