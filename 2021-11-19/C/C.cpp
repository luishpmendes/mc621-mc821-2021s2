#include <cmath>
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
};


// returns the area, which is half the determinant
double area(const std::vector<point> & P) {
    double result = 0.0;

    for (unsigned i = 0; i < P.size() - 1; i++) {
        result += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
    }
    
    return fabs(result) / 2.0;
}

int main () {
    unsigned n, result;
    std::vector<point> P;
    point p0, pi;
    double t, sheets_volume, r, manhole_volume;

    while (std::cin >> n && n) {
        sheets_volume = 0.0;

        while (n--) {        
            P.clear();

            std::cin >> t >> p0.x >> p0.y;
            P.push_back(p0);

            while (true) {
                std::cin >> pi.x >> pi.y;

                P.push_back(pi);

                if (pi == p0) {
                    break;
                }
            }

            sheets_volume += area(P) * t;
        }

        std::cin >> r >> t;

        manhole_volume = M_PI * r * r * t;

        result = sheets_volume / manhole_volume;

        std::cout << result << std::endl;
    }

    return 0;
}
