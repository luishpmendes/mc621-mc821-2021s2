#include <cmath>
#include <iostream>
#include <vector>

struct point {
    double x, y; // only used if more precision is needed

    point() { // default constructor
        x = y = 0.0;
    }

    point(double _x, double _y) : x(_x), y(_y) {} // user-defined
};

double hypot (double dx, double dy) {
    return sqrt(dx * dx + dy * dy);
}

double dist(point p1, point p2) { // Euclidean distance
    return hypot(p1.x - p2.x, p1.y - p2.y); // return double
}

bool circle2PtsRad (point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;

    if (det < 0.0) {
        return false;
    }

    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;

    return true; // to get the other center, reverse p1 and p2
}

int main () {
    unsigned n, i, j, k;
    std::vector<point> v;
    double r;
    bool result;
    point c;

    while (std::cin >> n) {
        if (n == 0) {
            break;
        }

        v.resize(n);

        for (i = 0; i < n; i++) {
            std::cin >> v[i].x >> v[i].y;
        }

        std::cin >> r;

        result = false;

        for (i = 0; i < n && !result; i++) {
            for (j = i + 1; j < n && !result; j++) {
                circle2PtsRad(v[i], v[j], r, c);

                for (k = 0; k < n; k++) {
                    if (dist(v[k], c) > r) {
                        break;
                    }
                }

                if (k == n) {
                    result = true;
                }
            }
        }

        if (result) {
            std::cout << "The polygon can be packed in the circle." << std::endl;
        } else {
            std::cout << "There is no way of packing that polygon." << std::endl;
        }
    }

    return 0;
}
