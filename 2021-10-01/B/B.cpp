#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main () {
    unsigned N, a, b, Q, k;
    std::vector<std::string> S;
    std::strint t;

    std::cin >> N >> a >> b;

    S.resize(N);

    for (std::string & s : S) {
        std::cin >> s;
    }

    std::sort(S.begin(), S.end());

    std::cin >> Q;

    while (Q--) {
        std::cin >> t;

    }

    return 0;
}

