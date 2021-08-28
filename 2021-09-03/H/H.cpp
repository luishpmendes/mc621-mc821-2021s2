#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

unsigned permutate (const std::vector<unsigned> & p, unsigned x) {
    unsigned result, i;
    std::vector<unsigned> v (p.size(), 0);

    for (i = v.size(); i > 0; i--) {
        v[p[i - 1]] = x % 10;
        x /= 10;
    }

    x = 1;
    result = 0;

    for (i = v.size(); i > 0; i--) {
        result += v[i - 1] * x;
        x *= 10;
    }

    return result;
}

int main () {
    unsigned n, k, i, min, max, result, val;
    std::vector<unsigned> v, p;

    while (std::cin >> n >> k) {
        result = std::numeric_limits<unsigned>::max();
        v.resize(n, 0);
        p.resize(k);
        std::iota(p.begin(), p.end(), 0);

        for (i = 0; i < n; i++) {
            std::cin >> v[i];
        }

        do {
            min = std::numeric_limits<unsigned>::max();
            max = std::numeric_limits<unsigned>::min();

            for (i = 0; i < n; i++) {
                val = permutate(p, v[i]);

                if (min > val) {
                    min = val;
                }

                if (max < val) {
                    max = val;
                }
            }

            if (result > max - min) {
                result = max - min;
            }
        } while (std::next_permutation(p.begin(), p.end()));

        std::cout << result << std::endl;
    }
    return 0;
}

