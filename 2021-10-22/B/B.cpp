#include <iostream>
#include <string>

int main () {
    unsigned n, k, i;
    std::string s, t, result, aux;

    while (std::cin >> n >> k >> s) {
        t = "";
        t += s[0];
        result = t;

        while (result.size() < k) {
            result += result;
        }

        while (result.size() > k) {
            result.pop_back();
        }

        for (i = 1; i < n && s[i] <= s.front(); i++) {
            t += s[i];
            aux = t;

            while (aux.size() < k) {
                aux += aux;
            }

            while (aux.size() > k) {
                aux.pop_back();
            }

            if (result > aux) {
                result = aux;
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}

