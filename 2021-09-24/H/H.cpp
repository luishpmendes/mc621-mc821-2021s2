#include <iostream>
#include <vector>

int main () {
    unsigned n, max_a, i;
    std::vector<unsigned> a, result;
    std::vector<bool> exist;

    while (std::cin >> n) {
        max_a = 1;
        a.resize(n);
        result.clear();

        for (i = 0; i < n; i++) {
            std::cin >> a[i];

            if (max_a < a[i]) {
                max_a = a[i];
            }
        }

        exist.clear();
        exist.resize(max_a + 1, false);

        for (i = n; i > 0; i--) {
            if (!exist[a[i - 1]]) {
                result.push_back(a[i - 1]);
            }

            exist[a[i - 1]] = true;
        }

        std::cout << result.size() << std::endl;

        for (i = result.size(); i > 1; i--) {
            std::cout << result[i - 1] << ' ';
        }

        std::cout << result.front() << std::endl;
    }

    return 0;
}

