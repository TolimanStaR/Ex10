// Copyright 2020 A.SHT
#include "../include/MyStack.h"
#include "../include/postfix.h"

std::map<char, int> priority{
        {'(', 0},
        {')', 1},
        {'+', 2},
        {'-', 2},
        {'*', 3},
        {'/', 3},
        {'.', 5},
        {'0', 5},
        {'1', 5},
        {'2', 5},
        {'3', 5},
        {'4', 5},
        {'5', 5},
        {'6', 5},
        {'7', 5},
        {'8', 5},
        {'9', 5},
};

std::vector<std::string> split(const std::string &s) {
    std::vector<std::string> container;
    std::string buffer;
    for (auto x : s) {
        if (x == ' ') {
            if (buffer.length() > 0) {
                container.push_back(buffer);
                buffer.clear();
            }
        } else {
            buffer += x;
        }
    }
    if (buffer.length() > 0)
        container.push_back(buffer);
    return container;
}

std::string normalize(const std::string &s) {
    std::string result;
    for (auto x : s) {
        if (x == ')' ||
            x == '(' ||
            x == '+' ||
            x == '-' ||
            x == '/' ||
            x == '*'
                ) {
            result += ' ';
            result += x;
            result += ' ';
        } else {
            result += x;
        }
    }
    return result;
}

std::string infix2postfix(std::string infix) {
    std::string result;
    MyStack<std::string> stack(1000);
    infix = normalize(infix);
    auto expression = split(infix);
    for (auto statement : expression) {
        if (priority[statement[0]] == 5)
            result += statement + ' ';
        else if (priority[statement[0]] == 0 ||
                 priority[stack.get()[0]] < priority[statement[0]] &&
                 priority[statement[0]] != 5 ||
                 stack.isEmpty()) {
            stack.push(statement);
        } else {
            if (statement != ")") {
                while (priority[stack.get()[0]] >= priority[statement[0]])
                    result += stack.pop() + ' ';
                stack.push(statement);
            } else {
                while (stack.get() != "(")
                    result += stack.pop() + ' ';
                stack.pop();
            }
        }
    }
    while (!stack.isEmpty())
        result += stack.pop() + ' ';
    result = result.substr(0, result.length() - 1);
    return result;
}
