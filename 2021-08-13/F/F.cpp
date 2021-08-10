#include <iostream>

unsigned mask(unsigned n) {
    unsigned result = 0,
             pot = 1;
    while(n > 0) {
        unsigned remainder = n % 10;
        if(remainder == 4 || remainder == 7) {
            result += remainder * pot;
            pot *= 10;
        }
        n /= 10;
    }
    return result;
}

int main() {
    unsigned a, b;
    while(std::cin >> a >> b) {
        unsigned c = a + 1;
        while (mask(c) != b) {
            c++;
        }
        std::cout << c << std::endl;
    }
    return 0;
}

