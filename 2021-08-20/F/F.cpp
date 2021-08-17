#include <iostream>

int main() {
    unsigned t, a, b, n;
    std::cin >> t;
    while (t--){
        std::cin >> a >> b >> n;
        switch (n % 3) {
            case 0:
                std::cout << a << std::endl;
                break;
            case 1:
                std::cout << b << std::endl;
                break;
            default:
                std::cout << (a^b) << std::endl;
        }
    }
    return 0;
}

