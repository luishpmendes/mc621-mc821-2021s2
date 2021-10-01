#include <iostream>
#include <string>

int main () {
    unsigned t, n, k;
    std::string s;

    std::cin >> t;

    while (t--) {
        std::cin >> n >> k;

        s = "";

        while (s.size() < n) {
            s += "abc";
        }

        while (s.size() > n) {
            s.pop_back();
        }

        std::cout << s << std::endl;
    }

    return 0;
}

