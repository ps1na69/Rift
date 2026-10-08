#pragma once

#include <memory>
#include <string>
#include <vector>

struct Expression
{
    enum class Type
    {
        Number,
        Identifier,
        Binary
    };

    Type type;

    int value = 0;
    std::string name;

    char operation = '\0';

    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
};

struct VariableDeclaration
{
    std::string name;
    std::string type;

    std::unique_ptr<Expression> value;
};

struct Function
{
    std::string name;
    std::vector<VariableDeclaration> variables;
};

struct Program
{
    std::vector<Function> functions;
};