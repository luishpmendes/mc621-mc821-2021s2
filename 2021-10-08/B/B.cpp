#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


// computes lps for a given pattern p
std::vector<unsigned> compute_lps (std::string p) {
    unsigned len = 0, // length of the previous longest prefix suffix
             i = 1;
    std::vector<unsigned> lps (p.size(), 0); // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to p.size() - 1
    while (i < p.size()) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } 
        // p[i] != p[len]
        else if (len != 0) {
            len = lps[len - 1];
        } else { // len == 0
            lps[i] = 0;
            i++;
        }
    }

    return lps;
}

// computes the occurrences of p in t
std::vector<unsigned> kmp_search(std::string p,
                                 std::string t,
                                 std::vector<unsigned> lps) {
    unsigned i, j; // indexes for t and p
    std::vector<unsigned> result;

    i = j = 0;

    while (i < t.size()) {
        if (p[j] == t[i]) {
            j++;
            i++;
        }

        if (j == p.size()) {
            result.push_back(i - j);
            j = lps[j - 1];
            break;
        } 
        // mismatch after j matches
        else if (i < t.size() && p[j] != t[i]) {
            // do not need to match lsp[0 .. lps[j - 1]] characters
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}

int main () {
    unsigned n, i, j;
    std::vector<std::string> m, mrev, mt, mtrev, md1, md1rev, md2, md2rev;
    std::string p;
    std::vector<unsigned> lps, result;
    std::vector<std::vector<std::pair<unsigned, unsigned>>> aux1, aux1rev, aux2, aux2rev;

    while (std::cin >> n) {
        m.resize(n);

        for (std::string & s : m) {
            std::cin >> s;
        }

        mrev = m;

        for (std::string & s : mrev) {
            std::reverse(s.begin(), s.end());
        }

        mt.clear();
        mt.resize(n, "");

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                mt[j] += m[i][j];
            }
        }

        mtrev = mt;

        for (std::string s : mtrev) {
            std::reverse(s.begin(), s.end());
        }

        md1.clear();
        md1.resize(2 * n - 1, "");
        aux1.clear();
        aux1.resize(2 * n - 1);

        for (j = 0; j < n; j++) {
            for (i = 0; i < n; i++) {
                md1[i + j].push_back(m[i][j]);
                aux1[i + j].push_back(std::make_pair(i, j));
            }
        }

        md1rev = md1;
        aux1rev = aux1;

        for (i = 0; i < 2 * n - 1; i++) {
            std::reverse(md1rev[i].begin(), md1rev[i].end());
            std::reverse(aux1rev[i].begin(), aux1rev[i].end());
        }

        md2.clear();
        md2.resize(2 * n - 1, "");
        aux2.clear();
        aux2.resize(2 * n - 1);

        for (j = 0; j < n; j++) {
            for (i = 0; i < n; i++) {
                md2[n + i - j - 1].push_back(m[i][j]);
                aux2[n + i - j - 1].push_back(std::make_pair(i, j));
            }
        }

        md2rev = md2;
        aux2rev = aux2;

        for (i = 0; i < 2 * n - 1; i++) {
            std::reverse(md2rev[i].begin(), md2rev[i].end());
            std::reverse(aux2rev[i].begin(), aux2rev[i].end());
        }

        while (std::cin >> p) {
            if (p.compare("0") == 0) {
                break;
            }

            result.clear();
            lps = compute_lps(p); // calculates the longest prefix suffix values of p

            if (p.size() <= n) {
                for (i = 0; i < n; i++) {
                    result = kmp_search(p, m[i], lps);

                    if (!result.empty()) {
                        break;
                    }
                }
        
                if (!result.empty()) {
                    std::cout << i + 1 << ','
                              << result.front() + 1 << ' '
                              << i + 1 << ','
                              << result.front() + p.size() << std::endl;
                    continue;
                }

                for (i = 0; i < n; i++) {
                    result = kmp_search(p, mrev[i], lps);

                    if (!result.empty()) {
                        break;
                    }
                }
        
                if (!result.empty()) {
                    std::cout << i + 1 << ','
                              << n - result.front() << ' '
                              << i + 1 << ','
                              << n + 1 - result.front() - p.size() << std::endl;
                    continue;
                }

                for (i = 0; i < n; i++) {
                    result = kmp_search(p, mt[i], lps);

                    if (!result.empty()) {
                        break;
                    }
                }

                if (!result.empty()) {
                    std::cout << result.front() + 1 << ','
                              << i + 1 << ' '
                              << result.front() + p.size()
                              << ',' << i + 1 << std::endl;
                    continue;
                }

                for (i = 0; i < n; i++) {
                    result = kmp_search(p, mtrev[i], lps);

                    if (!result.empty()) {
                        break;
                    }
                }

                if (!result.empty()) {
                    std::cout << result.front() + 1 << ','
                              << i + 1 << ' '
                              << result.front() - p.size()
                              << ',' << i + 1 << std::endl;
                    continue;
                }
            }

            for (i = 0; i < 2 * n - 1; i++) {
                if (p.size() <= md1[i].size()) {
                    result = kmp_search(p, md1[i], lps);
                }

                if (!result.empty()) {
                    break;
                }
            }

            if (!result.empty()) {
                std::cout << aux1[i][result.front()].first + 1 << ','
                          << aux1[i][result.front()].second + 1 << ' '
                          << aux1[i][result.front() + p.size() - 1].first + 1 << ','
                          << aux1[i][result.front() + p.size() - 1].second + 1 << std::endl;
                continue;
            }

            for (i = 0; i < 2 * n - 1; i++) {
                if (p.size() <= md1rev[i].size()) {
                    result = kmp_search(p, md1rev[i], lps);
                }

                if (!result.empty()) {
                    break;
                }
            }

            if (!result.empty()) {
                std::cout << aux1rev[i][result.front()].first + 1 << ','
                          << aux1rev[i][result.front()].second + 1 << ' '
                          << aux1rev[i][result.front() + p.size() - 1].first + 1 << ','
                          << aux1rev[i][result.front() + p.size() - 1].second + 1 << std::endl;
                continue;
            }

            for (i = 0; i < 2 * n - 1; i++) {
                if (p.size() <= md2[i].size()) {
                    result = kmp_search(p, md2[i], lps);
                }

                if (!result.empty()) {
                    break;
                }
            }

            if (!result.empty()) {
                std::cout << aux2[i][result.front()].first + 1 << ','
                          << aux2[i][result.front()].second + 1 << ' '
                          << aux2[i][result.front() + p.size() - 1].first + 1 << ','
                          << aux2[i][result.front() + p.size() - 1].second + 1 << std::endl;
                continue;
            }

            for (i = 0; i < 2 * n - 1; i++) {
                if (p.size() <= md2rev[i].size()) {
                    result = kmp_search(p, md2rev[i], lps);
                }

                if (!result.empty()) {
                    break;
                }
            }

            if (!result.empty()) {
                std::cout << aux2rev[i][result.front()].first + 1 << ','
                          << aux2rev[i][result.front()].second + 1 << ' '
                          << aux2rev[i][result.front() + p.size() - 1].first + 1 << ','
                          << aux2rev[i][result.front() + p.size() - 1].second + 1 << std::endl;
                continue;
            }

            std::cout << "Not found" << std::endl;
        }
    }

    return 0;
}

