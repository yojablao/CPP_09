#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>

class RPN {
private:
    std::stack<int> _stack;

    bool isOperator(const std::string &str) const;
    int aplyOperator(const std::string &oper, int a, int b) const;

public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();
    int mainfunc(const std::string &expr);
};

#endif
