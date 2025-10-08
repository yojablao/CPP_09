#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        RPN rpn;
        int result = rpn.mainfunc(argv[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
