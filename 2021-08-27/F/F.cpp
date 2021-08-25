#include <iostream>
#include <vector>

int main() {
    int n, k, i;
    std::vector<int> a;
    while (std::cin >> n >> k) {
        a.resize(n);
        for (i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        k--;
        if(a[k] == 0) {
            while (k >= 0 && a[k] == 0) {
                k--;
            }
        } else {
            while (k < n && a[k + 1] == a[k]) {
                k++;
            }
        }
        std::cout << k + 1 << std::endl;
    }
    return 0;
}

