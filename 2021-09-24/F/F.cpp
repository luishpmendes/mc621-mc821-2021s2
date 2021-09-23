#include <fstream>
#include <utility>

#define MAX_INDEX 20000000

long long f (long long a,
             long long b,
             long long c,
             long long x) {
    return (a * x + x % b) % c;
}

long long cycle_finding (long long a,
                         long long b,
                         long long c,
                         long long x0) {
    long long i,
              tortoise = f(a, b, c, x0),
              hare = f(a, b, c, f(a, b, c, x0)),
              mu = 0,
              lambda = 1;

    for (i = 0; i < MAX_INDEX && tortoise != hare; i++) {
        tortoise = f(a, b, c, tortoise);
        hare = f(a, b, c, f(a, b, c, hare));
    }

    hare = x0;

    for (i = 0; i < MAX_INDEX && tortoise != hare; i++) {
        tortoise = f(a, b, c, tortoise);
        hare = f(a, b, c, hare);
        mu++;
    }

    hare = f(a, b, c, tortoise);

    for (; i < MAX_INDEX && tortoise != hare; i++) {
        hare = f(a, b, c, hare);
        lambda++;
    }

    if (tortoise == hare) {
        return mu + lambda;
    }

    return -1;
}

int main () {
    std::ifstream ifs ("input.txt", std::ifstream::in);
    std::ofstream ofs ("output.txt", std::ofstream::out);

    long long a, b, c, x0 = 1;

    while (ifs >> a >> b >> c) {
        ofs << cycle_finding(a, b, c, x0) << std::endl;
    }

    ifs.close();
    ofs.close();

    return 0;
}

