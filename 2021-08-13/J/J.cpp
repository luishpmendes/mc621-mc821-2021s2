#include <iostream>
#include <string>

int main () {
    unsigned n, k;
    while (std::cin >> n >> k) {
        std::string d;
        std::cin >> d;
        for (unsigned x = 0; x < n - 1 && k > 0; x++) {
            if (d[x] == '4' && d[x + 1] == '7') {
                if ((x & 1) == 0) {
                    d[x + 1] = '4';
                } else {
                    if (x > 0 && d[x - 1] == '4') {
                        if((k & 1) == 0) {
                            d[x] = '4';
                        } else {
                            d[x] = '7';
                        }
                        break;
                    } else {
                        d[x] = '7';
                    }
                }
                k--;
            }
        }
        std::cout << d << std::endl;
    }
    return 0;
}

