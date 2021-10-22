#include <iostream>
#include <string>

int main() {
    unsigned n;
    std::string s;

    while (std::cin >> n) {
        while (n--) {
            std::cin >> s;
            if (s.size() <= 10) {
                std::cout << s << std::endl;
            } else {
                std::cout << s.front() << s.size() - 2 << s.back() << std::endl;
            }
        }
    }

    return 0;
}
