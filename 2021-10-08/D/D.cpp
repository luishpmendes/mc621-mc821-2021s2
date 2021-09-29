#include <iostream>
#include <string>
#include <vector>

int main () {
    unsigned n;
    std::string s;
    int balance;

    while (std::cin >> n >> s) {
        balance = 0;

        for (const char & c : s) {
            if (c == '1') {
                balance++;
            } else {
                balance--;
            }
        }
        if (balance) {
            std::cout << 1 << std::endl
                      << s << std::endl;
        } else {
            std::cout << 2 << std::endl
                      << s[0] << ' '
                      << s.substr(1) << std::endl;
        }
    }

    return 0;
}

