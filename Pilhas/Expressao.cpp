//verificar se uma expressão aritmética é válida:

#include <iostream>
#include <stack>
#include <string>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isValidExpression(std::string exp) {
    std::stack<char> stk;

    for (char c : exp) {
        if (c == '(') {
            stk.push(c);
        } else if (c == ')') {
            if (stk.empty() || stk.top() != '(') {
                return false;
            } else {
                stk.pop();
            }
        } else if (isOperator(c)) {
            if (stk.empty() || !isOperator(stk.top())) {
                return false;
            }
        } else {
            // ignore non-operator characters
        }
    }

    // the stack should be empty if the expression is valid
    return stk.empty();
}

int main() {
    std::string exp = "(a+b)*(c-d)";

    if (isValidExpression(exp)) {
        std::cout << "Expression is valid" << std::endl;
    } else {
        std::cout << "Expression is not valid" << std::endl;
    }

    return 0;
}
