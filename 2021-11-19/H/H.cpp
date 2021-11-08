#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#define EPS 1E-9

struct point {
    double x, y; // only used if more precision is needed

    point() { // default constructor
        x = y = 0.0;
    }

    point(double _x, double _y) : x(_x), y(_y) {} // user-defined

    // use EPS (1e-9) when testing equality of two floating points
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }

    bool operator != (point other) const {
        return !(*this == other);
    }
};

double dist(point p1, point p2) { // Euclidean distance
    return hypot(p1.x - p2.x, p1.y - p2.y); // return double
}

// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const std::vector<point> & P) {
    double result = 0.0;

    for (unsigned i = 0; i < P.size() - 1; i++) // remember that P[0] = P[n-1]
        result += dist(P[i], P[i + 1]);

    return result;
}

int main() {
    unsigned n, k, t, r, i;
    std::vector<point> P, Q;
    double tree_interval, distance_from_last_tree, d;

    std::cout << std::fixed << std::setprecision(2);

    while (std::cin >> n) {
        for (r = 1; r <= n; r++) {
            std::cin >> k >> t;

            P.resize(k);
            Q.clear();

            for (point & p : P) {
                std::cin >> p.x >> p.y;
            }

            tree_interval = perimeter(P) / (t - 1.0);

            Q.push_back(P.front());
            distance_from_last_tree = 0.0;

            for (i = 1; i < k ; i++) {
                d = dist(P[i - 1], P[i]);
                distance_from_last_tree += d;

                while (distance_from_last_tree >= tree_interval) {
                    Q.push_back(point(P[i].x + (distance_from_last_tree - tree_interval) * (P[i - 1].x - P[i].x) / d,
                                      P[i].y + (distance_from_last_tree - tree_interval) * (P[i - 1].y - P[i].y) / d));
                    distance_from_last_tree -= tree_interval;
                }
            }

            if (Q.back() != P.back()) {
                Q.push_back(P.back());
            }

            std::cout << "Road #" << r << ":" << std::endl;

            for (const point & p : Q) {
                std::cout << p.x << " " << p.y << std::endl;
            }

            std::cout << std::endl;
        }
    } 

    return 0;
}
