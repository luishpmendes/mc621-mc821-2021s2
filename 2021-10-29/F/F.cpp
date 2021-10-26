#include <iostream>
#include <vector>

int main () {
    unsigned n, a;
    unsigned long long count, result;

    while (std::cin >> n) {
        count = result = 0;

        while (n--) {
            std::cin >> a;

            if (a) {
                count++;
            } else {
                result += count;
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}
