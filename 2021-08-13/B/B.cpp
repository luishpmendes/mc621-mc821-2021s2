#include <iostream>
#include <vector>

int main() {
    unsigned n;
    while (std::cin >> n) {
        std::vector<unsigned> programmers, mathematicians, sportsmans;
        for(unsigned i = 1; i <= n; i++) {
            unsigned t;
            std::cin >> t;
            if (t == 1) {
                programmers.push_back(i);
            } else if (t == 2) {
                mathematicians.push_back(i);
            } else {
                sportsmans.push_back(i);
            }
        }
        unsigned w = programmers.size();
        if (w > mathematicians.size()) {
            w = mathematicians.size();
        }
        if (w > sportsmans.size()) {
            w = sportsmans.size();
        }
        std::cout << w << std::endl;
        for(unsigned i = 0; i < w; i++) {
            std::cout << programmers[i] << " " 
                      << mathematicians[i] << " "
                      << sportsmans[i] << std::endl;
        }
    }
    return 0;
}

