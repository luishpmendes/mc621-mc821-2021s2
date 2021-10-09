#include <iostream>
#include <string>
#include <list>

int main () {
    std::list<std::string> l;
    std::string s;
    unsigned max_size, diff, i;
    bool flag = false;

    while (std::getline(std::cin, s)) {
        l.push_back(s);
    }

    max_size = l.front().size();

    for (const std::string & t : l) {
        if (max_size < t.size()) {
            max_size = t.size();
        }
    }

    for (std::string & t : l) {
        diff = max_size - t.size();

        if ((diff & 1) == 1 && flag) {
            t = " " + t;
        }

        for (i = 0; i < diff / 2; i++) {
            t = " " + t;
        }

        for (i = 0; i < diff / 2; i++) {
            t = t + " ";
        }

        if ((diff & 1) == 1) {
            if (!flag) {
                t = t + " ";
            }

            flag = !flag;
        }
    }

    s = "";

    for (i = 0; i < max_size; i++) {
        s = s + "*";
    }

    l.push_front(s);
    l.push_back(s);

    for (std::string & t : l) {
        t = "*" + t + "*";
    }

    for (const std::string t : l) {
        std::cout << t << std::endl;
    }

    return 0;
}

