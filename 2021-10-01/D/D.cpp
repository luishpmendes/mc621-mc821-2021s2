#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>

unsigned prejuizo(std::list<unsigned> & A) {
    unsigned prejuizoA, prejuizoB;
    prejuizoA = prejuizoB = 0;

    for (auto it = A.begin(); it != A.end(); it++) {
        if (std::next(it) == A.end()) {
            break;
        }
        prejuizoA += abs((*it) - (*std::next(it)));
        it++;
    }

    for (auto it = A.rbegin(); it != A.rend(); it++) {
        if (std::next(it) == A.rend()) {
            break;
        }
        prejuizoB += abs((*it) - (*std::next(it)));
        it++;
    }

    if (prejuizoA < prejuizoB) {
        return prejuizoA;
    } else {
        return prejuizoB;
    }
}

int main () {
    unsigned N, Q, a;
    std::list<unsigned> A;

    std::cin >> N >> Q;

    A.resize(N);

    for (unsigned & aux : A) {
        std::cin >> aux;
    }

    A.sort();

    std::cout << prejuizo(A) << std::endl;

    while (Q--) {
        std::cin >> a;
        A.insert(std::lower_bound(A.begin(), A.end(), a), a);
        std::cout << prejuizo(A) << std::endl;
    }

    return 0;
}

