#include <iostream>

int main () {
    unsigned long long n, result;
    while (std::cin >> n) {
        result = 1;
        result *= n;
        result *= (n - 1);
        result *= (n - 2);
        result *= (n - 3);
        result *= (n - 4);
        result /= 5;
        result /= 4;
        result /= 3;
        result /= 2;
        result *= n;
        result *= (n - 1);
        result *= (n - 2);
        result *= (n - 3);
        result *= (n - 4);
        std::cout << result << std::endl;
    }
}

