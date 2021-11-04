#include <iostream>
#include <set>
#include <utility>

int gcd (int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main () {
    int n, x0, y0, x, y, z;
    std::set<std::pair<int, int>> s;

    while (std::cin >> n >> x0 >> y0) {
        s.clear();

        while (n--) {
            std::cin >> x >> y;
            x -= x0;
            y -= y0;
            z = gcd(x, y);
            s.insert(std::make_pair(x / z, y / z));
        }

        std::cout << s.size() << std::endl;
    }

    return 0;
}
