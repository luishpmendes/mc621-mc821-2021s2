#include <iostream>
#include <string>

int main () {
    unsigned n, i, pointsL, pointsKira, setsL, setsKira;
    std::string s;

    pointsL = pointsKira = setsL = setsKira = 0;

    std::cin >> n;

    for (i = 0; i < n; i++) {
        std::cin >> s;

        if (s.compare("L") == 0) {
            pointsL++;
        } else if (s.compare("Kira") == 0) {
            pointsKira++;
        }

        if ((pointsL == 4 && pointsKira <= 2) || (pointsL >= 4 && pointsL >= pointsKira + 2)) {
            setsL++;
            pointsL = pointsKira = 0;
        } else if ((pointsKira == 4 && pointsL <= 2) || (pointsKira >= 4 && pointsKira >= pointsL + 2)) {
            setsKira++;
            pointsL = pointsKira = 0;
        }

        if ((setsL == 2 && setsKira == 0) || setsL == 3) {
            std::cout << "L eh melhor que Kira!!!" << std::endl;
            break;
        } else if ((setsKira == 2 && setsL == 0) || setsKira == 3) {
            std::cout << "Kira eh melhor que L!!!" << std::endl;
            break;
        }
    }


    return 0;
}

