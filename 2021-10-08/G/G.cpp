#include <iostream>
#include <string>

int main () {
    std::string s;
    unsigned i;

    while (std::cin >> s) {
        for (i = 0; i < s.size(); i++) {
            if (s[i] == 'h') {
                break;
            }
        }
        for (i++; i < s.size(); i++) {
            if (s[i] == 'e') {
                break;
            }
        }
        for (i++; i < s.size(); i++) {
            if (s[i] == 'i') {
                break;
            }
        }
        for (i++; i < s.size(); i++) {
            if (s[i] == 'd') {
                break;
            }
        }
        for (i++; i < s.size(); i++) {
            if (s[i] == 'i') {
                break;
            }
        }
        if (i < s.size()) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

