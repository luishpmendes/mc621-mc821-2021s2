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
};

struct vec { // name: ‘vec’ is different from STL vector
    double x, y;

    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) { // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}

double angle(point a, point o, point b) { // returns angle aob in rad
    vec oa = toVec(o, a),
        ob = toVec(o, b);

    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns the area, which is half the determinant
double area(const std::vector<point> & P) {
    double result = 0.0;
    unsigned i;

    for (i = 0; i < P.size() - 1; i++) {
        result += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
    }

    return fabs(result) / 2.0;
}

// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const std::vector<point> & P) {
    if (P.size() == 0) {
        return false;
    }

    double sum = 0.0; // assume the first vertex is equal to the last vertex
    unsigned i;

    for (i = 0; i < P.size() - 1; i++) {
        if (ccw(pt, P[i], P[i+1])) {
            sum += angle(P[i], pt, P[i+1]); // left turn/ccw
        } else {
            sum -= angle(P[i], pt, P[i+1]); // right turn/cw
        }
    }

    return fabs(fabs(sum) - 2 * M_PI) < EPS;
}

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
    double a = B.y - A.y,
           b = A.x - B.x,
           c = B.x * A.y - A.x * B.y,
           u = fabs(a * p.x + b * p.y + c),
           v = fabs(a * q.x + b * q.y + c);

    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
std::vector<point> cutPolygon(point a, point b, const std::vector<point> & Q) {
    std::vector<point> P;
    unsigned i;
    double left1, left2;

    for (i = 0; i < Q.size(); i++) {
        left1 = cross(toVec(a, b), toVec(a, Q[i]));
        left2 = 0;

        if (i != Q.size() - 1) {
            left2 = cross(toVec(a, b), toVec(a, Q[i + 1]));
        }

        if (left1 > -EPS) { // Q[i] is on the left of ab
            P.push_back(Q[i]);
        }
        
        if (left1 * left2 < -EPS) { // edge (Q[i], Q[i+1]) crosses line ab
            P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
        }
    }

    if (!P.empty() && !(P.back() == P.front())) {
        P.push_back(P.front()); // make P’s first point = P’s last point
    }

    return P;
}

int main() {
    unsigned n, w, h, t;
    point p, p1, p2;
    std::vector<point> P;

    std::cout << std::fixed << std::setprecision(3);

    t = 0;

    while (std::cin >> n >> w >> h >> p.x >> p.y) {
        P.clear();
        P.push_back(point(0, 0));
		P.push_back(point(w, 0));
		P.push_back(point(w, h));
		P.push_back(point(0, h));
		P.push_back(point(0, 0));

        while (n--) {
            std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
            
            if (ccw(p1, p2, p)) {
                P = cutPolygon(p1, p2, P);
            } else {
                P = cutPolygon(p2, p1, P);
            }
        }

        std::cout << "Case #" << ++t << ": " << area(P) << std::endl;
    }

    return 0;
}
