#include "interpreter.h"

#include <iostream>
#include <stdexcept>
#include <unordered_map>

void Interpreter::run(const Program& program)
{
    for (const auto& function : program.functions) {
        if (function.name == "main") {
            runFunction(function);
            return;
        }
    }

    throw std::runtime_error("No main function");
}

void Interpreter::runFunction(const Function& function)
{
    std::unordered_map<std::string, int> variables;

    for (const auto& variable : function.variables) {
        int value = evaluate(*variable.value);

        variables[variable.name] = value;

        std::cout << variable.name
            << " = "
            << value
            << '\n';
    }
}

int Interpreter::evaluate(const Expression& expression)
{
    switch (expression.type) {
    case Expression::Type::Number:
        return expression.value;

    case Expression::Type::Binary:
    {
        int left = evaluate(*expression.left);
        int right = evaluate(*expression.right);

        switch (expression.operation) {
        case '+':
            return left + right;

        default:
            throw std::runtime_error("Unknown operator");
        }
    }

    case Expression::Type::Identifier:
        throw std::runtime_error(
            "Identifier evaluation is not implemented yet"
        );
    }

    throw std::runtime_error("Unknown expression");
}