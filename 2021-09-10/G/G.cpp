#include <iostream>
#include <map>
#include <set>
#include <vector>

unsigned long long const MOD = 1e9 + 7,
                         MAX_N = 200200,
                         MAX_VAL = 200200;

void add (unsigned long long i,
          unsigned long long a,
          unsigned long long n,
          const std::vector<unsigned long long> & nxt,
          std::vector<std::multiset<unsigned long long>> & cnt,
          std::vector<std::map<unsigned long long, unsigned long long>> & cnt_divisor,
          unsigned long long & result) {
    unsigned long long div, aux, lst, lst_min, j;

    while (a > 1) {
        div = nxt[a];
        aux = 0;

        while (nxt[a] == div) {
            aux++;
            a = a / nxt[a];
        }

        lst = cnt_divisor[i][div];
        cnt_divisor[i][div] += aux;
        lst_min = 0;

        if (cnt[div].size() == n) {
            lst_min = (*cnt[div].begin());
        }

        if (lst != 0) {
            cnt[div].erase(cnt[div].find(lst));
        }

        cnt[div].insert(lst + aux);

        if (cnt[div].size() == n) {
            for (j = lst_min + 1; j <= (*cnt[div].begin()); j++) {
                result = (result * div) % MOD;
            }
        }
    }
}

int main () {
    unsigned long long n, q, x, i, j, result;
    std::vector<unsigned long long> a, nxt;
    std::vector<std::multiset<unsigned long long>> cnt;
    std::vector<std::map<unsigned long long, unsigned long long>> cnt_divisor;

    while (std::cin >> n >> q) {
        result = 1;
        a.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        nxt.clear();
        nxt.resize(std::max(n, MAX_VAL), 0);

        for (i = 2; i < MAX_N ; i++) {
            if (nxt[i] == 0) {
                nxt[i] = i;

                if (i > 10000) {
                    continue;
                }

                for (j = i * i; j < MAX_N; j += i) {
                    if (nxt[j] == 0) {
                        nxt[j] = i;
                    }
                }
            }
        }

        cnt.clear();
        cnt.resize(MAX_VAL);
        cnt_divisor.clear();
        cnt_divisor.resize(MAX_N);

        for (i = 0; i < n; i++) {
            add(i + 1, a[i], n, nxt, cnt, cnt_divisor, result);
        }

        for (i = 0; i < q; i++) {
            std::cin >> j >> x;
            add(j, x, n, nxt, cnt, cnt_divisor, result);
            std::cout << result << std::endl;
        }
    }

    return 0;
}

