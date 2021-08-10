#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string a, b;
    while(std::cin >> a >> b) {
        unsigned c47 = 0,
                 c74 = 0;
        for (unsigned i = 0; i < a.size() && i < b.size(); i++) {
            if (a[i] == '4' && b[i] == '7') {
                c47++;
            } else if (a[i] == '7' && b[i] == '4') {
                c74++;
            }
        }
        if (c47 >= c74) {
            std::cout << c47 << std::endl;
        } else {
            std::cout << c74 << std::endl;
        }
    }
}

