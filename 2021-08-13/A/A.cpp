#include <algorithm>
#include <iostream>
#include <vector>

void generate(unsigned x, unsigned n, std::vector<unsigned> & lucky_numbers) {
    if (x > 0) {
        lucky_numbers.push_back(x);
    }
    if (x < n/2) {
        generate(10*x+4, n, lucky_numbers);
        generate(10*x+7, n, lucky_numbers);
    }
}

int main() {
    unsigned n;
    while(std::cin >> n) {
        std::vector<unsigned> lucky_numbers;
        generate(4, n, lucky_numbers);
        generate(7, n, lucky_numbers);
        std::sort(lucky_numbers.begin(), lucky_numbers.end());
        bool almost_lucky = false;
        for(const auto & lucky_number : lucky_numbers) {
            if(n % lucky_number == 0) {
                almost_lucky = true;
                break;
            }
        }
        if(almost_lucky) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}

