#include <iostream>
#include <string>

int main() {
    std::string s;
    while (std::cin >> s) {
        unsigned count4 = 0,
                 count7 = 0;
        for (const char & c : s) {
            if (c == '4') {
                count4++;
            } else if (c == '7') {
                count7++;
            }
        }
        if (count4 == 0 && count7 == 0) {
            std::cout << "-1" << std::endl;
        } else if (count4 >= count7) {
            std::cout << "4" << std::endl;
        } else {
            std::cout << "7" << std::endl;
        }
    }
    return 0;
}

