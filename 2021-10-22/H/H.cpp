#include <iostream>
#include <string>

int main () {
    std::string s, i, f;

    while (std::cin >> s) {
        i = s.substr(0, s.find('.'));
        f = s.substr(s.find('.') + 1);

        if (i.back() == '9') {
            std::cout << "GOTO Vasilisa." << std::endl;
        } else {
            if (f.front() >= '5') {
                i.back()++;
            }

            std::cout << i << std::endl;
        }
    }

    return 0;
}

