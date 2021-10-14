#include <iostream>

int main () {
    unsigned short h, m;
    char c;

    while (std::cin >> h >> c >> m) {
        do {
            m++;
            h += m / 60;
            m %= 60;
            h %= 24;

        } while (h / 10 != m % 10 || h % 10 != m / 10);

        std::cout << h / 10 << h % 10 << ':' << m / 10 << m % 10 << std::endl;
    }

    return 0;
}

