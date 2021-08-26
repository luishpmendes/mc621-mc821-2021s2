#include <iostream>
#include <string>

int main () {
    std::string n;
    while (std::cin >> n) {
        if (n.size() < 3 || (n.size() == 3 && n.compare("127") <= 0)) {
            std::cout << "byte" << std::endl;
        } else if (n.size() < 5 || (n.size() == 5 && n.compare("32767") <= 0)) {
            std::cout << "short" << std::endl;
        } else if (n.size() < 10 || (n.size() == 10 && n.compare("2147483647") <= 0)) {
            std::cout << "int" << std::endl;
        } else if (n.size() < 19 || (n.size() == 19 && n.compare("9223372036854775807") <= 0)) {
            std::cout << "long" << std::endl;
        } else {
            std::cout << "BigInteger" << std::endl;
        }
    }
    return 0;
}

