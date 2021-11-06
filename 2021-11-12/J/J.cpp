#include <iostream>

int main () {
    unsigned n, i, w, h, max_index;
    double size, max_size;

    while (std::cin >> n && n) {
        max_size = max_index = 0;

        for (i = 0; i < n; i++) {
            std::cin >> w >> h;

            if (w < h) {
                size = w / 2.0;
            } else {
                size = h / 2.0;
            }

            if (w < 4 * h) {
                if (size < w / 4.0) {
                    size = w / 4.0;
                }
            } else {
                if (size < h) {
                    size = h;
                }
            }

            if (4 * w < h) {
                if (size < w) {
                    size = w;
                }
            } else {
                if (size < h / 4.0) {
                    size = h / 4.0;
                }
            }

            if (max_size < size) {
                max_size = size;
                max_index = i;
            }
        }

        std::cout << max_index + 1 << std::endl;
    }

    return 0;
}
