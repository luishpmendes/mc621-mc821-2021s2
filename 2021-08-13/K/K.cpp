#include <iostream>
#include <string>

int main() {
    unsigned n;
    while(std::cin >> n) {
        std::string ticket;
        std::cin >> ticket;
        bool lucky = true;
        for(const char & c : ticket) {
            if(c != '4' && c != '7') {
                lucky = false;
                break;
            }
        }
        if(lucky) {
            unsigned sum1 = 0,
                     sum2 = 0;
            for(unsigned i = 0; i < n/2; i++) {
                sum1 += ticket[i] - '0';
            }
            for(unsigned i = n/2; i < n; i++) {
                sum2 += ticket[i] - '0';
            }
            lucky = (sum1 == sum2);
        }
        if(lucky) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}

