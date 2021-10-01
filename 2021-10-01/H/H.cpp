#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

int main () {
    unsigned n, q, i;
    std::map<std::string, unsigned> country2id;
    std::vector<std::string> t;
    std::vector<unsigned> g, p, b;
    std::string w;
    unsigned m, first, second, third;

    std::cin >> n >> q;
    t.resize(n);
    g.resize(n);
    p.resize(n);
    b.resize(n);

    for (i = 0; i < n; i++) {
        std::cin >> t[i] >> g[i] >> p[i] >> b[i];
        country2id[t[i]] = i;
    }

    first = 0;

    for (i = 1; i < n; i++) {
        if (g[i] > g[first] || 
           (g[i] == g[first] && p[i] > p[first]) || 
           (g[i] == g[first] && p[i] == p[first] && b[i] > b[first]) ||
           (g[i] == g[first] && p[i] == p[first] && b[i] == b[first] && t[i] > t[first])) {
            first = i;
        }
    }

    second = 0;

    if (second == first) {
        second++;
    }

    for (i = 0; i < n; i++) {
        if (i == first) {
            continue;
        }
        if (g[i] > g[second] || 
           (g[i] == g[second] && p[i] > p[second]) || 
           (g[i] == g[second] && p[i] == p[second] && b[i] > b[second]) ||
           (g[i] == g[second] && p[i] == p[second] && b[i] == b[second] && t[i] > t[second])) {
            second = i;
        }
    }

    third = 0;

    while (third == first || third == second) {
        third++;
    }

    for (i = 0; i < n; i++) {
        if (i == first || i == second) {
            continue;
        }
        if (g[i] > g[third] || 
           (g[i] == g[third] && p[i] > p[third]) || 
           (g[i] == g[third] && p[i] == p[third] && b[i] > b[third]) ||
           (g[i] == g[third] && p[i] == p[third] && b[i] == b[third] && t[i] > t[third])) {
            third = i;
        }
    }

    std::cout << t[first] << ' ' << t[second] << ' ' << t[third] << std::endl;

    while (q--) {
        std::cin >> w >> m;

        i = country2id[w];

        if (m == 1) {
            g[i]++;
        } else if (m == 2) {
            p[i]++;
        } else if (m == 3) {
            b[i]++;
        }

        if (i == second) {
            if (g[i] > g[first] || 
               (g[i] == g[first] && p[i] > p[first]) || 
               (g[i] == g[first] && p[i] == p[first] && b[i] > b[first]) ||
               (g[i] == g[first] && p[i] == p[first] && b[i] == b[first] && t[i] > t[first])) {
                second = first;
                first = i;
            }
        } else if (i == third) {
            if (g[i] > g[second] || 
               (g[i] == g[second] && p[i] > p[second]) || 
               (g[i] == g[second] && p[i] == p[second] && b[i] > b[second]) ||
               (g[i] == g[second] && p[i] == p[second] && b[i] == b[second] && t[i] > t[second])) {
                third = second;
                second = i;

                if (g[i] > g[first] || 
                    (g[i] == g[first] && p[i] > p[first]) || 
                    (g[i] == g[first] && p[i] == p[first] && b[i] > b[first]) ||
                    (g[i] == g[first] && p[i] == p[first] && b[i] == b[first] && t[i] > t[first])) {
                    second = first;
                    first = i;
                }
            }
        } else if (i != first) {
            if (g[i] > g[third] || 
               (g[i] == g[third] && p[i] > p[third]) || 
               (g[i] == g[third] && p[i] == p[third] && b[i] > b[third]) ||
               (g[i] == g[third] && p[i] == p[third] && b[i] == b[third] && t[i] > t[third])) {
                third = i;

                if (g[i] > g[second] || 
                   (g[i] == g[second] && p[i] > p[second]) || 
                   (g[i] == g[second] && p[i] == p[second] && b[i] > b[second]) ||
                   (g[i] == g[second] && p[i] == p[second] && b[i] == b[second] && t[i] > t[second])) {
                    third = second;
                    second = i;

                    if (g[i] > g[first] || 
                       (g[i] == g[first] && p[i] > p[first]) || 
                       (g[i] == g[first] && p[i] == p[first] && b[i] > b[first]) ||
                       (g[i] == g[first] && p[i] == p[first] && b[i] == b[first] && t[i] > t[first])) {
                        second = first;
                        first = i;
                    }
                }
            }
        }

        std::cout << t[first] << ' ' << t[second] << ' ' << t[third] << std::endl;
    }

    return 0;
}

