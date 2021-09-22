#include <iostream>
#include <utility>
#include <vector>

int main () {
    unsigned long long t, a, b, k, result;
    std::vector<std::pair<unsigned long long, unsigned long long>> edges;
    std::vector<unsigned long long> degA, degB;

    std::cin >> t;

    while (t--) {
        std::cin >> a >> b >> k;

        edges.resize(k);
        degA.clear();
        degA.resize(a, 0);
        degB.clear();
        degB.resize(b, 0);

        for (auto &[u, v] : edges) {
            std::cin >> u;
            u--;
        }

        for (auto &[u, v] : edges) {
            std::cin >> v;
            v--;
        }

        for (auto &[u, v] : edges) {
            degA[u]++;
            degB[v]++;
        }

        result = 0;

        for (auto &[u, v] : edges) {
            result += k - degA[u] - degB[v] + 1;
        }

        std::cout << result / 2 << std::endl;
    }

    return 0;
}

