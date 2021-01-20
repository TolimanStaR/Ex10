// Copyright 2020 A.SHT

#include "../include/postfix.h"

signed main() {
    std::cout << infix2postfix("(1.324+2)*3+4-(4/2.3332)/7") << '\n';
    std::cout << infix2postfix("(1 + 2) / (3 + 4 * 6.7) - 5.3 * 4.4") << '\n';
    std::cout << infix2postfix("2 + 6 * 3 / (4 - 2)") << '\n';
    std::string inf = "2 + 6 * 3 / (4 - 2)";
    std::string postf = infix2postfix(inf);
    std::string expected = "2 6 3 * 4 2 - / +";
    std::cout << (postf == expected);
    return 0;
}
