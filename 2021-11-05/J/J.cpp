#include <cmath>
#include <iomanip>
#include <iostream>

struct point {
    double x, y; // only used if more precision is needed

    point() { // default constructor
        x = y = 0.0;
    }

    point(double _x, double _y) : x(_x), y(_y) {} // user-defined
};

double hypot(double dx, double dy) {
    return sqrt(dx * dx + dy * dy);
}

double dist(point p1, point p2) { // Euclidean distance
    return hypot(p1.x - p2.x, p1.y - p2.y); // return double
}


struct vec { // name: ‘vec’ is different from STL vector
    double x, y;

    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) { // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) { // nonnegative s = [<1 .. 1 .. >1]
    return vec(v.x * s, v.y * s); // shorter.same.longer
}

point translate(point p, vec v) { // translate p according to v
    return point(p.x + v.x , p.y + v.y);
}

double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c); // Euclidean distance between p and c
}

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);

    if (u < 0.0) {
        c = point(a.x, a.y); // closer to a
        return dist(p, a); // Euclidean distance between p and a
    }

    
    if (u > 1.0) {
        c = point(b.x, b.y); // closer to b
        return dist(p, b); // Euclidean distance between p and b
    }

    return distToLine(p, a, b, c);
}

int main () {
    unsigned n, i;
    double xm, ym, x0, y0, x1, y1, distance, minimalDistance;
    point m, p0, p1, p, c;
    std::cout << std::fixed << std::setprecision(4);

    while (std::cin >> xm >> ym >> n) {
        m = point(xm, ym);
        std::cin >> x0 >> y0 >> x1 >> y1;
        p0 = point(x0, y0);
        p1 = point(x1, y1);
        minimalDistance = distToLineSegment(m, p0, p1, c);

        for (i = 0; i < n - 1; i++) {
            x0 = x1;
            y0 = y1;
            std::cin >> x1 >> y1;
            p0 = point(x0, y0);
            p1 = point(x1, y1);
            distance = distToLineSegment(m, p0, p1, p);

            if (distance < minimalDistance) {
                minimalDistance = distance;
                c = p;
            }
        }

        std::cout << c.x << std::endl << c.y << std::endl;
    }

    return 0;
}
