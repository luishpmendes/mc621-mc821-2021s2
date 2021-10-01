#include <iostream>
#include <map>

int main () {
    unsigned n, t, x, fracos;
    std::map<unsigned, unsigned> r;

    while (std::cin >> n) {
        r.clear();

        while (n--) {
            std::cin >> t >> x;

            if (t == 1) {
                if (r.find(x) == r.end()) {
                    r[x] = 1;
                } else {
                    r[x]++;
                }
            } else if (t == 2) {
                if (r[x] == 1) {
                    r.erase(x);
                } else {
                    r[x]--;
                }
            } else if (t == 3) {
                fracos = 0;

                for (const auto & [y, count] : r) {
                    if ((y & x) == x) {
                        fracos += count;
                    }
                }

                std::cout << fracos << std::endl;
            }
        }
    }

    return 0;
}

