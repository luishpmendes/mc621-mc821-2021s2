#include <iostream>
#include <vector>

typedef unsigned long long ull;

#define MOD 1000000007

bool good (ull sum, ull a, ull b) {
    ull digit;
    while(sum) {
        digit = sum%10;
        if(digit != a && digit != b) {
            return false;
        }
        sum /= 10;
    }
    return true;
}

ull power(ull base, ull p) {
    ull result = 1;
    while (p) {
        if (p & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        p >>= 1;
    }
    return result;
}

int main () {
    ull a, b, n, i, sum, result;
    std::vector<ull> fact(1e6+10, 1);
    // pre-compute factorials
    for (i = 1; i < fact.size(); i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    while (std::cin >> a >> b >> n) {
        result = 0;
        for (i = 0; i <= n; i++) {
            // check if a number with i a's and (n - i) b's is excellent
            // that is, check if the sum of its digits is good
            sum = a * i + b * (n - i);
            if (good(sum, a, b)) {
                // add the C(i, n) % MOD combinations to the results
                // C(i, n) = n!/(i!*(n-i)!) % MOD 
                //         = n! * ((i! * (n - i)!)^(MOD - 2)) % MOD
                result += (fact[n] * (power((fact[i] * fact[n - i]) % MOD, MOD - 2) % MOD)) % MOD;
                result %= MOD;
            }
        }
        std::cout << result << std::endl;
    }
    return 0;
}

