#include <iostream>

int main () {
    int n, d, m, x, y;

    while (std::cin >> n >> d >> m) {
        while (m--) {
            std::cin >> x >> y;

            if ((x - y) > d || (x - y) < -d || (x + y) > n + n - d || (x + y) < d) {
		    	std::cout << "NO" << std::endl;
            } else {
                std::cout << "YES" << std::endl;
            }
        }
    }

    return 0;
}
