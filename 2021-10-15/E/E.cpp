#include <algorithm>
#include <iostream>
#include <string>

int main () {
    unsigned n;
    std::string s;

    while (std::cin >> n >> s) {
        std::sort(s.begin(), s.end());
        std::cout << s << std::endl;
    }

    return 0;
}

