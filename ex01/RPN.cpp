#include "RPN.hpp"
#include <sstream>
#include <iostream>

RPN::RPN() {}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other) {
    if (this != &other) this->_stack = other._stack;
    return *this;
}
RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::aplyOperator(const std::string &op, int a, int b) const {
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
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && isdigit(token[0])) {
            _stack.push(token[0] - '0');
        }
        else if (isOperator(token)) {
            if (_stack.size() < 2)
                throw std::runtime_error("err");
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            int result = aplyOperator(token, a, b);
            _stack.push(result);
        }
        else {
            throw std::runtime_error("err");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("err");

    return _stack.top();
}
