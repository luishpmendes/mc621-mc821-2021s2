#include <iostream>
#include <vector>

int main() {
    std::vector<unsigned long> f = {0, 1};
    while (f.back() <= 1e9) {
        f.push_back(f.back() + f[f.size() - 2]);
    }
    unsigned long n;
    while (std::cin >> n) {
        if (n == 0) {
            std::cout << "0 0 0" << std::endl;
        } else if (n == 1) {
            std::cout << "0 0 1" << std::endl;
        } else if (n == 2) {
            std::cout << "0 1 1" << std::endl;
        } else {
            unsigned l = 0, 
                     r = f.size();
            while (l < r) {
                unsigned m = (l + r)/2;
                if(n <= f[m]) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            while (f[l+1] == n){
                l++;
            }
            std::cout << f[l - 4] << " "
                      << f[l - 3] << " "
                      << f[l - 1] << std::endl;
        }
    }
    return 0;
}

