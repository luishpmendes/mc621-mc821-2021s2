#include <algorithm>
#include <iostream>
#include <iterator>
#include <deque>
#include <vector>

int main () {
    unsigned n, m, q, t, x, l, r;
    std::vector<unsigned> ls, rs, xs, counts;
    int d;

    std::deque<unsigned> v;

    std::cin >> n >> m >> q;

    v.resize(n, 0);

    for (unsigned & vi : v) {
        std::cin >> vi;
    }


    while (q--) {
        std::cin >> t;

        if (t == 1) {
            std::cin >> d >> x;

            if (d == -1) {
                v.push_front(x);
                for (unsigned & aux : ls) {
                    aux += 1;
                }
                for (unsigned & aux : rs) {
                    aux += 1;
                }

            } else if (d == 1) {
                v.push_back(x);
            }
        } else if (t == 2) {
            std::cin >> l >> r >> x;
            ls.push_back(l - 1);
            rs.push_back(r - 1);
            xs.push_back(x);
            counts.push_back(0);
//            std::cout << std::count(v.begin() + l - 1,
//                                    v.begin() + r,
//                                    x) << std::endl;
        }
    }

//    std::cout << "v : ";
//    for (unsigned i = 0; i < v.size(); i++) {
//        std::cout << v[i] << ' ';
//    }
//    std::cout << std::endl;
//    for (unsigned j = 0; j < xs.size(); j++) {
//        std::cout << "l : " << ls[j] << std::endl;
//        std::cout << "r : " << rs[j] << std::endl;
//        std::cout << "x : " << xs[j] << std::endl << std::endl;
//    }

    for (unsigned i = 0; i < v.size(); i++) {
        for (unsigned j = 0; j < xs.size(); j++) {
            if (i >= ls[j] && i <= rs[j] && v[i] == xs[j]) {
                counts[j]++;
            }
        }
    }

    for (unsigned count : counts) {
        std::cout << count << std::endl;
    }

    return 0;
}

