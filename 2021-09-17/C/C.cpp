#include <iostream>
#include <string>

int main () {
    unsigned n, d, sum_digits;
    std::string y;
    bool has_zero, has_one_even, has_two_even;

    std::cin >> n;

    while (n--) {
        std::cin >> y;
        sum_digits = 0;
        has_zero = has_one_even = has_two_even = false;

        for (const char & c : y) {
            d = c - '0';
            sum_digits += d;
            if (has_one_even && (d & 1) == 0) {
                has_two_even = true;
            }
            if ((d & 1) == 0) {
                has_one_even = true;
            }
            if (d == 0) {
                has_zero = true;
            }
        }

        if (has_zero && has_two_even && sum_digits % 3 == 0) {
            std::cout << "red" << std::endl;
        } else {
            std::cout << "cyan" << std::endl;
        }
    }

    return 0;
}

