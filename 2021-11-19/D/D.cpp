#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#define EPS 1e-9

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

struct vec { // name: ‘vec’ is different from STL vector
    double x, y;

    vec(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2) { // Euclidean distance
    return hypot(p1.x - p2.x, p1.y - p2.y); // return double
}

vec toVec(point a, point b) { // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// returns the area, which is half the determinant
double area(const std::vector<point> & P) {
    double result = 0.0;

    for (unsigned i = 0; i < P.size() - 1; i++) {
        result += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
    }

    result /= 2.0;

    return result;
}

std::vector<point> CH(std::vector<point> P) { // the content of P may be reshuffled
    unsigned i, j, n = P.size();

    if (n <= 3) {
        if (!(P[0] == P[n - 1])) { // safeguard from corner case
            P.push_back(P[0]);
        }

        return P; // special case, the CH is P itself
    }

    // first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = 0;

    for (i = 1; i < n; i++) {
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)) {
            P0 = i;
        }
    }

    // swap P[P0] with P[0]
    point temp = P[0];
    P[0] = P[P0];
    P[P0] = temp;

    // second, sort points by angle w.r.t. pivot P0
    // we do not sort P[0]
    sort(++P.begin(),
         P.end(),
         [P](point a, point b) { // angle-sorting function
            if (collinear(P[0], a, b)) { // special case
                return dist(P[0], a) < dist(P[0], b); // check which one is closer
            }

            double d1x = a.x - P[0].x,
                   d1y = a.y - P[0].y,
                   d2x = b.x - P[0].x,
                   d2y = b.y - P[0].y;

            return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; // compare two angles
        }
    );

    // third, the ccw tests
    // initial S
    std::vector<point> S;
    S.push_back(P[n - 1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    
    i = 2; // then, we check the rest

    while (i < n) { // note: N must be >= 3 for this method to work
        j = S.size() - 1;
        if (ccw(S[j - 1], S[j], P[i])) {
            // left turn, accept
            S.push_back(P[i++]);
        } else {
            // or pop the top of S until we have a left turn
            S.pop_back();
        }
    }

    return S;
}

point centroid(const std::vector<point> & P) {
    point result;
    unsigned i;
    double a;

    for (i = 0; i < P.size() - 1; i++) {
        result.x += (P[i].x + P[i + 1].x) * (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
        result.y += (P[i].y + P[i + 1].y) * (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
    }

    a = area(P);
    result.x /= 6.0 * a;
    result.y /= 6.0 * a;

    return result;
}

int main() {
    unsigned n;
    std::vector<point> P;
    point result;

    std::cout << std::fixed << std::setprecision(3);

    while (std::cin >> n && n > 2) {
        P.resize(n);

        for (point & p : P) {
            std::cin >> p.x >> p.y;
        }

        result = centroid(CH(P));

        std::cout << result.x << ' ' << result.y << std::endl;
    }

    return 0;
}
