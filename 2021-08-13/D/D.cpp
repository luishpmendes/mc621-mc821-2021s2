#include <algorithm>
#include <iostream>
#include <vector>

void generate(long long unsigned x,
        long long unsigned l, long long unsigned r,
        std::vector<long long unsigned> & lucky_numbers) {
    if (x >= l) {
        lucky_numbers.push_back(x);
    }
    if (x < r) {
        generate(10*x+4, l, r, lucky_numbers);
        generate(10*x+7, l, r, lucky_numbers);
    }
}

int main() {
    long long unsigned l, r;
    while (std::cin >> l >> r) {
        std::vector<long long unsigned> lucky_numbers;
        generate(4, l, r, lucky_numbers);
        generate(7, l, r, lucky_numbers);
        std::sort(lucky_numbers.begin(), lucky_numbers.end());
        long long unsigned result = 0;
        for (long long unsigned i = 0; i <= lucky_numbers.size(); i++) {
            if (lucky_numbers[i] <= r) {
                result += (lucky_numbers[i] - l + 1) * lucky_numbers[i];
                l = lucky_numbers[i] + 1;
            } else {
                result += (r - l + 1) * lucky_numbers[i];
                break;
            }
        }
        std::cout << result << std::endl;
    }
    return 0;
}

