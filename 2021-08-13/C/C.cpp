#include <algorithm>
#include <iostream>
#include <vector>

void generate(unsigned long long lucky_number,
              unsigned fours,
              unsigned sevens,
              std::vector<unsigned long long> & super_lucky) {
    if(lucky_number <= 1e10) {
        if(fours == sevens) {
            super_lucky.push_back(lucky_number);
        }

        generate(lucky_number * 10 + 4, fours + 1, sevens, super_lucky);
        generate(lucky_number * 10 + 7, fours, sevens + 1, super_lucky);
    }
}

int main() {
    std::vector<unsigned long long> super_lucky;

    generate(4, 1, 0, super_lucky);
    generate(7, 0, 1, super_lucky);

    std::sort(super_lucky.begin(), super_lucky.end());

    unsigned long long n;
    while (std::cin >> n) {
        std::cout << *std::lower_bound(super_lucky.begin(),
                                       super_lucky.end(),
                                       n) << std::endl;
    }
}

