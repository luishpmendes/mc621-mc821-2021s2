#include <iostream>
#include <set>

int main () {
    unsigned n;
    int x, y;
    std::set<int> a, b;

    while (std::cin >> n) {
        a.clear();
        b.clear();

        while (n--) {
            std::cin >> x >> y;
            a.insert(x);
            b.insert(y);
        }

        if (a.size() != 2 || b.size() != 2) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << ((*a.rbegin()) - (*a.begin())) * ((*b.rbegin()) - (*b.begin())) << std::endl;
        }
    }

    return 0;
}
