#include <iostream>
#include <string>

#define MOD 1000000007

typedef unsigned long long ull;

struct Matrix {
    ull mat [55][55];
};

Matrix matMul(Matrix a, Matrix b, ull m) {
    Matrix result;
    ull i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            for (result.mat[i][j] = k = 0; k < m; k++) {
                result.mat[i][j] += ((a.mat[i][k] % MOD) * (b.mat[k][j] % MOD)) % MOD;
                result.mat[i][j] %= MOD;
            }
        }
    }
    return result;
}

Matrix matPow(Matrix base, ull p, ull m) {
    Matrix result;
    ull i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            result.mat[i][j] = (i == j);
        }
    }
    while (p) {
        if (p & 1) {
            result = matMul(result, base, m);
        }
        base = matMul(base, base, m);
        p >>= 1;
    }
    return result;
}

int main () {
    ull n, m, k, i, j, u, v, result;
    std::string s;
    Matrix M;
    while (std::cin >> n >> m >> k) {
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                M.mat[i][j] = 1;
            }
        }
        while (k--) {
            std::cin >> s;
            if(s.front() >= 'a' && s.front() <= 'z') {
                u = s.front() - 'a';
            } else {
                u = (s.front() - 'A') + 26;
            }
            if(s.back() >= 'a' && s.back() <= 'z') {
                v = s.back() - 'a';
            } else {
                v = (s.back() - 'A') + 26;
            }
            M.mat[u][v] = 0;
        }
        M = matPow(M, n - 1, m);
        result = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                result = (result + M.mat[i][j]) % MOD;
            }
        }
        std::cout << result << std::endl;
    }
}

