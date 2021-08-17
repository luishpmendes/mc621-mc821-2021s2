#include <iostream>
#include <vector>

int main () {
    unsigned n;
    while (std::cin >> n) {
        std::vector<unsigned long long> a(n);
        for (unsigned i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        if(n <= 2) {
            std::cout << n << std::endl;
        } else {
            unsigned curLen, maxLen;
            curLen = maxLen = 2;
            for (unsigned i = 2; i < n; i++) {
                if(a[i] == a[i - 1] + a[i - 2]) {
                    curLen++;
                } else {
                    if (maxLen < curLen) {
                        maxLen = curLen;
                    }
                    curLen = 2;
                }
            }
            if (maxLen < curLen) {
                maxLen = curLen;
            }
            std::cout << maxLen << std::endl;
        }
    }
    return 0;
}

