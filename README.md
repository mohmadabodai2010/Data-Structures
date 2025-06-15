# Data Structures

A comprehensive collection of fundamental data structures implemented in C++.

## Overview

This repository provides clear, efficient, and well-documented implementations of classic data structures in C++. It is designed for students, educators, and developers seeking to understand, practice, or utilize foundational data structures. The code is organized for easy reference and extension.

## Features

- **Wide Range of Data Structures:**  
  Includes stacks, queues, linked lists (singly, doubly, and circular), trees, heaps, hash tables, and more.
- **Template-Based Implementations:**  
  Most structures are implemented using C++ templates for type generality.
- **Educational Clarity:**  
  Code is structured and commented for learning and easy adaptation.
- **Test Cases:**  
  Example usage and test files are provided for each data structure.
- **No External Dependencies:**  
  All implementations use standard C++.

## Data Structures Included

- Stack (array and linked list)
- Queue (array, circular, and linked list)
- Singly Linked List
- Doubly Linked List
- Circular Linked List
- Binary Tree (basic operations)
- Binary Search Tree (BST)
- Heap (min-heap and max-heap)
- Hash Table (basic implementation)
- Additional structures as the repository evolves

## Usage

### 1. Clone the repository

```bash
git clone https://github.com/TareqAlKushari/Data-Structures.git
cd Data-Structures
```

### 2. Include the desired header(s) in your project

```cpp
#include "stack.h"
#include "queue.h"
#include "singly_linked_list.h"
// etc.
```

### 3. Example

```cpp
#include <iostream>
#include "stack.h"

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    std::cout << s.top() << std::endl; // 2
    s.pop();
    std::cout << s.top() << std::endl; // 1
    return 0;
}
```

### 4. Build and Run Tests

Each structure may have a corresponding test file, e.g., `test_stack.cpp`:

```bash
g++ -std=c++11 test_stack.cpp -o test_stack
./test_stack
```

## Contributing

Contributions, suggestions, and bug reports are welcome! Please open an issue or submit a pull request.

## License

This project is licensed under the MIT License.

---

*Created by [TareqAlKushari](https://github.com/TareqAlKushari)*
