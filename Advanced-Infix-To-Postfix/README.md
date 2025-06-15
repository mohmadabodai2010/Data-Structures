# Expression Converter Evaluator C++

A C++ library and toolset for converting and evaluating mathematical expressions.

## Overview

This repository provides a robust C++ implementation for parsing, converting, and evaluating mathematical expressions. It supports conversion between infix, postfix (Reverse Polish Notation), and prefix notations, as well as direct evaluation of expressions. The project is designed for educational purposes, use in compilers/interpreters, calculators, or any application requiring expression manipulation.

## Features

- **Expression Conversion:**  
  - Infix to Postfix (RPN)
  - Infix to Prefix
  - Postfix to Infix
  - Prefix to Infix
- **Expression Evaluation:**  
  - Evaluates both postfix and prefix expressions
  - Supports integer and floating-point operands
  - Handles basic arithmetic operators: `+`, `-`, `*`, `/`, `^`, and parentheses
- **Error Handling:**  
  - Detects invalid expressions and division by zero
- **Extensible Design:**  
  - Template-based and easy to extend for more operators

## Usage

### 1. Clone the repository

```bash
git clone https://github.com/TareqAlKushari/expression-converter-evaluator-cpp.git
cd expression-converter-evaluator-cpp
```

### 2. Include the headers in your project

```cpp
#include "expression_converter.h"
#include "expression_evaluator.h"
```

### 3. Example

```cpp
#include <iostream>
#include "expression_converter.h"
#include "expression_evaluator.h"

int main() {
    std::string infix = "3 + 4 * 2 / (1 - 5) ^ 2";
    std::string postfix = ExpressionConverter::infixToPostfix(infix);
    double result = ExpressionEvaluator::evaluatePostfix(postfix);

    std::cout << "Infix: " << infix << std::endl;
    std::cout << "Postfix: " << postfix << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```

## API Reference

- `std::string ExpressionConverter::infixToPostfix(const std::string&)`
- `std::string ExpressionConverter::infixToPrefix(const std::string&)`
- `std::string ExpressionConverter::postfixToInfix(const std::string&)`
- `std::string ExpressionConverter::prefixToInfix(const std::string&)`
- `double ExpressionEvaluator::evaluatePostfix(const std::string&)`
- `double ExpressionEvaluator::evaluatePrefix(const std::string&)`

## Building & Running

If provided, tests and example programs can be compiled with a C++ compiler:

```bash
g++ -std=c++11 main.cpp expression_converter.cpp expression_evaluator.cpp -o expr_eval
./expr_eval
```

## Contributing

Contributions, suggestions, and bug reports are welcome! Please open an issue or submit a pull request.

## License

This project is licensed under the MIT License.

---

*Created by [TareqAlKushari](https://github.com/TareqAlKushari)*
