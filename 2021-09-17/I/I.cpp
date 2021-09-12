#include <iostream>

unsigned long long gcd (unsigned long long a, unsigned long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

unsigned long long lcm (unsigned long long a, unsigned long long b) {
    return a * (b / gcd(a, b));
}

int main () {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    unsigned long long n, k, c, aux;

    while (std::cin >> n >> k) {
        aux = 1;

        while (n--) {
            std::cin >> c;
            aux = gcd(k, lcm(aux, c));
        }

        if (aux == k) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}

