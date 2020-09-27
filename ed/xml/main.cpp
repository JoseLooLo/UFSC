#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.h"

int main() {

    char xmlfilename[100];

    std::cin >> xmlfilename;  // entrada

    parser::Parser parser(xmlfilename);
    if (parser.parseFile()) {
        printf("error!\n");
        return 0;
    } else {
        printf("psé\n");
        return 0;
    }

    std::cout << xmlfilename << std::endl;  // esta linha deve ser removida

    return 0;
}
