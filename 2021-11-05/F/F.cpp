#include <algorithm>
#include <iostream>
#include <vector>

struct point {
    int x, y;

    point() { // default constructor
        x = y = 0;
    }

    point(int _x, int _y) : x(_x), y(_y) {} // user-defined

    bool operator < (point other) const { // override less than operator
        if (x != other.x) { // useful for sorting
            return x < other.x; // first criteria , by x-coordinate
        }

        return y < other.y; // second criteria, by y-coordinate
    }

    bool operator == (point other) const {
        return (x == other.x && y == other.y);
    }
};

// rotate p by 90 degrees CCW w.r.t origin (0, 0)
point rotate(point p) {
    return point(-p.y, p.x);
}

int main () {
    unsigned t, n, i;
    int x, y;
    std::vector<point> p, q;

    while (std::cin >> t) {
        while (t--) {
            std::cin >> n;
            p.resize(n);
            q.resize(n);

            for (i = 0; i < n; i++) {
                std::cin >> x >> y;
                p[i] = point(x, y);
            }

            std::sort(p.begin(), p.end());

            for (i = 1; i < n; i++) {
                p[i].x -= p[0].x;
                p[i].y -= p[0].y;
            }

            p[0].x = 0;
            p[0].y = 0;

            for (i = 0; i < n; i++) {
                std::cin >> x >> y;
                q[i] = point(x, y);
            }

            std::sort(q.begin(), q.end());

            for (i = 1; i < n; i++) {
                q[i].x -= q[0].x;
                q[i].y -= q[0].y;
            }

            q[0].x = 0;
            q[0].y = 0;

            if (std::equal(p.begin(), p.end(), q.begin())) {
                std::cout << "MATCHED" << std::endl;
                continue;
            }

            std::transform(q.begin(), q.end(), q.begin(), rotate);
            std::sort(q.begin(), q.end());

            for (i = 1; i < n; i++) {
                q[i].x -= q[0].x;
                q[i].y -= q[0].y;
            }

            q[0].x = 0;
            q[0].y = 0;

            if (std::equal(p.begin(), p.end(), q.begin())) {
                std::cout << "MATCHED" << std::endl;
                continue;
            }

            std::transform(q.begin(), q.end(), q.begin(), rotate);
            std::sort(q.begin(), q.end());

            for (i = 1; i < n; i++) {
                q[i].x -= q[0].x;
                q[i].y -= q[0].y;
            }

            q[0].x = 0;
            q[0].y = 0;

            if (std::equal(p.begin(), p.end(), q.begin())) {
                std::cout << "MATCHED" << std::endl;
                continue;
            }

            std::transform(q.begin(), q.end(), q.begin(), rotate);
            std::sort(q.begin(), q.end());

            for (i = 1; i < n; i++) {
                q[i].x -= q[0].x;
                q[i].y -= q[0].y;
            }

            q[0].x = 0;
            q[0].y = 0;

            if (std::equal(p.begin(), p.end(), q.begin())) {
                std::cout << "MATCHED" << std::endl;
                continue;
            }

            std::cout << "NOT MATCHED" << std::endl;
        }
    }

    return 0;
}
