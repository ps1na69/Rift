#pragma once

#include "ast.h"

#include <string>
#include <unordered_map>

class Interpreter
{
public:
    void run(const Program& program);

private:
    void runFunction(const Function& function);

    int evaluate(const Expression& expression);

    std::unordered_map<std::string, int> variables_;
};