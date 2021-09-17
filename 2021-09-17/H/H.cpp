#include <iostream>

typedef long long ll;

inline ll pow (ll a, ll b, ll p) {
    ll result = 1;

    for (; b; b >>= 1) {
        if (b & 1) {
            result = (result * a) % p;
        }

        a = (a * a) % p;
    }

    return result;
}

inline ll inv (ll x, ll p) {
    return pow (x, p - 2, p);
}

int main () {
    ll a, b, p, x, result, j, y, i;

    while (std::cin >> a >> b >> p >> x) {
        result = 0;

        for (j = 1; j <= p - 1; j++) {
            y = b * inv(pow(a, j, p), p) % p;
            i = (p - 1) * ((j - y + p) % p) + j;

            if (i <= x) {
                result += 1 + (x - i) / (p * (p - 1));
            }
        }

        std::cout << result << std::endl;
    }


    return 0;
}

