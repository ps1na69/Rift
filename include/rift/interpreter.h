#pragma once

#include "ast.h"

class Interpreter
{
public:
    void run(const Program& program);

private:
    void runFunction(const Function& function);

    int evaluate(const Expression& expression);
};