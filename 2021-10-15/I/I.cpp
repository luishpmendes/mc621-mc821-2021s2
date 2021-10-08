#include <iostream>
#include <string>

int main () {
    unsigned t, n, q, l, r, i;
    std::string s;
    bool bad;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n >> q >> s;

            while (q--) {
                std::cin >> l >> r;
                l--;
                r--;
                bad = true;

                for (i = 0; i < l && bad; i++) {
                    if (s[i] == s[l]) {
                        bad = false;
                    }
                }

                for (i = r + 1; i < n && bad; i++) {
                    if (s[i] == s[r]) {
                        bad = false;
                    }
                }

                if (bad) {
                    std::cout << "NO" << std::endl;
                } else {
                    std::cout << "YES" << std::endl;
                }
            }
        }
    }

    return 0;
}

