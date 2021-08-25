#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::string s;
    bool has_upper, has_lower, has_digit;
    while (std::cin >> s) {
        has_upper = has_lower = has_digit = false;
        for (const char & c : s) {
            if (isupper(c)) {
                has_upper = true;
            } else if (islower(c)) {
                has_lower = true;
            } else if (isdigit(c)) {
                has_digit = true;
            }
            if(has_upper && has_lower && has_digit) {
                break;
            }
        }
        if (s.size() >= 5 && has_upper && has_lower && has_digit) {
            std::cout << "Correct" << std::endl;
        } else {
            std::cout << "Too weak" << std::endl;
        }
    }
    return 0;
}

