#include <iostream>
#include <string>

unsigned gcd (unsigned a, unsigned b) {
    return b == 0 ? a : gcd(b, a % b);
}

unsigned lcm (unsigned a, unsigned b) {
    return a * (b / gcd(a, b));
}

int main () {
    unsigned q, n, i;
    std::string s, t, u, v;

    std::cin >> q;

    while (q--) {
        std::cin >> s >> t;

        u = v = "";

        n = lcm(s.size(), t.size());

        for (i = 0; i < n / s.size(); i++) {
            u += s;
        }

        for (i = 0; i < n / t.size(); i++) {
            v += t;
        }

        if (u.compare(v) == 0) {
            std::cout << u << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}

