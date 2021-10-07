#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main () {
    unsigned t, n, k, sum, i, j, last_sum, pos, w, f;
    std::string s, a;
    std::vector<unsigned> v;
    bool flag;

    std::cin >> t;

    while (t--) {
        std::cin >> n >> k >> s;

        if (n % k != 0) {
            std::cout << -1 << std::endl;
        } else {
            v.clear();
            v.resize(26, 0);

            for (const char & c : s) {
                v[c - 'a']++;
            }

            sum = 0;

            for (const unsigned & x : v) {
                sum += (k - x % k) % k;
            }

            if (sum == 0) {
                std::cout << s << std::endl;
            } else {
                flag = true;
                for (i = n; i > 0 && flag; i--) {
                    sum -= (k - v[s[i - 1] - 'a'] % k) % k;
                    v[s[i - 1] - 'a']--;
                    sum += (k - v[s[i - 1] - 'a'] % k) % k;

                    for (j = s[i - 1] - 'a' + 1; j < 26; j++) {
                        last_sum = sum;
                        sum -= (k - v[j] % k) % k;
                        v[j]++;
                        sum += (k - v[j] % k) % k;

                        if (i + sum <= n) {
                            for (pos = 0; pos + 1 < i; pos++) {
                                std::cout << s[pos];
                            }

                            std::cout << char('a' + j);

                            a = "";

                            for (w = 0; w < 26; w++) {
                                f = (k - v[w] % k) % k;

                                while (f) {
                                    f--;
                                    a += char('a' + w);
                                }
                            }

                            while (a.size() + i < n) {
                                a += "a";
                            }

                            std::sort(a.begin(), a.end());
                            std::cout << a << std::endl;
                            flag = 0;
                            break;
                        }

                        v[j]--;
                        sum = last_sum;
                    }
                }
            }
        }
    }

    return 0;
}

