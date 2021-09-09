#include <iostream>
#include <vector>

unsigned long long gcd (unsigned long long a, unsigned long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main () {
    unsigned long long n, i, result;
    std::vector<unsigned long long> a, pre, suf;

    while (std::cin >> n) {
        a.resize(n + 1);
        pre.resize(n + 1);
        suf.resize(n + 1);

        for (i = 1; i <= n; i++) {
            std::cin >> a[i];
        }

        pre[1] = a[1];

        for (i = 2; i <= n; i++) {
            pre[i] = gcd(pre[i - 1], a[i]);
        }

        suf[n] = a[n];

        for (i = n - 1; i >= 1; i--) {
            suf[i] = gcd(a[i], suf[i + 1]);
        }

        result = suf[2];

        for (i = 1; i < n - 1; i++) {
            result *= gcd(pre[i], suf[i + 2]) / gcd(gcd(pre[i], suf[i + 2]), result);
        }

        result *= pre[n - 1] / gcd(pre[n - 1], result);

        std::cout << result << std::endl;
    }

    return 0;
}

