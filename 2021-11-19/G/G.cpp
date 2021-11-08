#include <cmath>
#include <iostream>

#define EPS 1E-9

struct point {
    double x, y; // only used if more precision is needed

    point() { // default constructor
        x = y = 0.0;
    }

    point(double _x, double _y) : x(_x), y(_y) {} // user-defined
};

struct vec { // name: ‘vec’ is different from STL vector
    double x, y;

    vec() { // default constructor
        x = y = 0.0;
    }

    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) { // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

int main () {
    point a, b, c;
    vec ab, bc;
    double x;

    while (std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
        ab = toVec(a, b);
        bc = toVec(b, c);
        x = cross(ab, bc);

        if (fabs(x) < EPS) {
            std::cout << "TOWARDS" << std::endl;
        } else if (x < 0) {
            std::cout << "RIGHT" << std::endl;
        } else {
            std::cout << "LEFT" << std::endl;
        }

    }

    return 0;
}
