#include "interpreter.h"

#include <iostream>
#include <stdexcept>

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
    variables_.clear();

    for (const auto& statement : function.statements) {
        if (statement.type == Statement::Type::VariableDeclaration) {
            const auto& variable = *statement.variable;

            int value = evaluate(*variable.value);

            variables_[variable.name] = value;
        }
        else if (statement.type == Statement::Type::Print) {
            int value = evaluate(*statement.expression);

            std::cout << value << '\n';
        }
    }
}

int Interpreter::evaluate(const Expression& expression)
{
    switch (expression.type) {
    case Expression::Type::Number:
        return expression.value;

    case Expression::Type::Identifier:
    {
        auto it = variables_.find(expression.name);

        if (it == variables_.end()) {
            throw std::runtime_error(
                "Undefined variable: " + expression.name
            );
        }

        return it->second;
    }

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
    }

    throw std::runtime_error("Unknown expression");
}