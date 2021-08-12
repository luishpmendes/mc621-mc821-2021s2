#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

int main() {
    unsigned n;
    while (std::cin >> n) {
        if (n & 1) {
            std::cout << "-1" << std::endl;
        } else {
            std::vector<unsigned> p(n, 0);
            std::iota(p.begin(), p.end(), 1);
            for (unsigned i = 1; 2*i <= n; i++) {
                std::swap(p[2*i-2], p[2*i-1]);
            }
            for (unsigned i = 0; i < n - 1; i++) {
                std::cout << p[i] << " ";
            }
            std::cout << p[n - 1] << std::endl;
        }
    }
}

