#include "RPN.hpp"
#include <sstream>
// #include <iostream>

RPN::RPN() {}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other) {
    if (this != &other) this->stak = other.stak;
    return *this;
}
RPN::~RPN() {}

bool RPN::isOper(const std::string &tok) const
{
    return (tok == "+" || tok == "-" || tok == "*" || tok == "/");
}

int RPN::aplyOper(const std::string &op, int a, int b) const {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0)
            throw std::runtime_error("err");
        return a / b;
    }
    throw std::runtime_error("err");
}

int RPN::mainfunc(const std::string &expr) {
    std::istringstream ss(expr);
    std::string to;

    while (ss >> to) {
        if (to.size() == 1 && isdigit(to[0])) {
            stak.push(to[0] - '0');
        }
        else if (isOper(to)) {
            if (stak.size() < 2)
                throw std::runtime_error("err");
            int b = stak.top();
            stak.pop();
            int a = stak.top();
            stak.pop();
            int result = aplyOper(to, a, b);
            stak.push(result);
        }
        else {
            throw std::runtime_error("err");
        }
    }

    if (stak.size() != 1)
        throw std::runtime_error("err");

    return stak.top();
}
