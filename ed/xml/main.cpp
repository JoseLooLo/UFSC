#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.h"

int main() {

    char xmlfilename[100];

    std::cin >> xmlfilename;  // entrada

    parser::Parser parser(xmlfilename);
    if (parser.parseFile()) {
        std::cout << "error\n" << std::endl;
        return 0;
    } else {
        return 0;
    }

    return 0;
}
