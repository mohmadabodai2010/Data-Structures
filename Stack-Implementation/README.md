# Stack C++

A simple, efficient, and reusable Stack data structure implementation in C++.

## Overview

This repository provides a generic Stack implementation in C++. The stack data structure is a fundamental collection type that follows the Last-In-First-Out (LIFO) principle, making it useful for various algorithms and applications such as expression evaluation, backtracking, and function call management.

## Features

- **Generic Template-Based Design:** Supports any data type.
- **Dynamic Memory Management:** Handles memory allocation and deallocation efficiently.
- **Standard Stack Operations:** Includes `push`, `pop`, `top`, `isEmpty`, and `size`.
- **Exception Safety:** Throws exceptions on invalid operations (e.g., popping from an empty stack).
- **Lightweight and Easy to Integrate:** No external dependencies.

## Usage

### 1. Clone the repository

```bash
git clone https://github.com/TareqAlKushari/stack-cpp.git
cd stack-cpp
```

### 2. Include the Stack header in your project

```cpp
#include "stack.h"
```

### 3. Example

```cpp
#include <iostream>
#include "stack.h"

int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    std::cout << "Top element: " << s.top() << std::endl; // 20
    s.pop();
    std::cout << "Top element after pop: " << s.top() << std::endl; // 10
    return 0;
}
```

## Building & Running Tests

If provided, tests can be built and run using a C++ compiler. Example using g++:

```bash
g++ -std=c++11 test_stack.cpp -o test_stack
./test_stack
```

## API Reference

- `void push(const T& value);` – Adds an element to the top of the stack.
- `void pop();` – Removes the top element from the stack.
- `T& top();` – Returns a reference to the top element.
- `bool isEmpty() const;` – Checks if the stack is empty.
- `size_t size() const;` – Returns the number of elements in the stack.

## Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License.

---

*Created by [TareqAlKushari](https://github.com/TareqAlKushari)*
