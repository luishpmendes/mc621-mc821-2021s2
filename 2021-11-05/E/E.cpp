#include <cmath>
#include <iomanip>
#include <iostream>

#define EPS 1E-9

struct point {
    double x, y; // only used if more precision is needed

    point() { // default constructor
        x = y = 0.0;
    }

    point(double _x, double _y) : x(_x), y(_y) {} // user-defined
};


struct line {
    // a way to represent a line
    double a, b, c;
}; 

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
        // default values
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) {
    // check coefficients a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
    // also check coefficient c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) {
        return false;
    }

    // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) {
        p.y = -(l1.a * p.x + l1.c);
    } else {
        p.y = -(l2.a * p.x + l2.c);
    }

    return true;
}

int main () {
    unsigned n;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    point p1, p2, p3, p4, p;
    line l1, l2;

    while (std::cin >> n) {
        std::cout << "INTERSECTING LINES OUTPUT" << std::endl << std::fixed << std::setprecision(2);

        while (n--) {
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

            p1 = point(x1, y1);
            p2 = point(x2, y2);
            p3 = point(x3, y3);
            p4 = point(x4, y4);

            pointsToLine(p1, p2, l1);
            pointsToLine(p3, p4, l2);

            if (areIntersect(l1, l2, p)) {
                std::cout << "POINT" << ' ' << p.x << ' ' << p.y << std::endl;
            } else if (areSame(l1, l2)) {
                std::cout << "LINE" << std::endl;
            } else {
                std::cout << "NONE" << std::endl;
            }
        }

        std::cout << "END OF OUTPUT" << std::endl;
    }

    return 0;
}
