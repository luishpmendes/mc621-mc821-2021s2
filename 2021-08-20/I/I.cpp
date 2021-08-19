#include <iostream>
#include <vector>

typedef unsigned long long ull;

#define MOD 1000000007

struct Matrix {
    ull mat [4][4];
};

Matrix matMul(Matrix a, Matrix b) {
    Matrix result;
    ull i, j, k;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (result.mat[i][j] = k = 0; k < 4; k++) {
                result.mat[i][j] += (a.mat[i][k] % MOD) * (b.mat[k][j] % MOD);
                result.mat[i][j] %= MOD;
            }
        }
    }
    return result;
}

Matrix matPow(Matrix base, ull p) {
    Matrix result;
    ull i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            result.mat[i][j] = (i == j);
        }
    }
    while (p) {
        if (p & 1) {
            result = matMul(result, base);
        }
        base = matMul(base, base);
        p >>= 1;
    }
    return result;
}

int main () {
    Matrix m;
    ull n;
    while (std::cin >> n) {
        ull i, j;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                m.mat[i][j] = (i != j);
            }
        }
        m = matPow(m, n);
        std::cout << m.mat[0][0] << std::endl;
    }
    return 0;
}

