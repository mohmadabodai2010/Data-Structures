# Singly Linked List C++

A simple and efficient implementation of a singly linked list in C++.

## Overview

This repository provides a generic singly linked list data structure written in C++. The singly linked list allows dynamic memory management and efficient insertions and deletions, making it suitable for various applications such as queues, stacks, and fundamental algorithm demonstrations.

## Features

- **Template-Based Design:** Supports any data type.
- **Core Operations:** Includes insertion, deletion, search, and traversal.
- **Memory Safe:** Proper handling of dynamic memory allocation and deallocation.
- **Lightweight & Easy to Use:** No external dependencies.

## Usage

### 1. Clone the repository

```bash
git clone https://github.com/TareqAlKushari/singly-linked-list-cpp.git
cd singly-linked-list-cpp
```

### 2. Include the Linked List header in your project

```cpp
#include "singly_linked_list.h"
```

### 3. Example

```cpp
#include <iostream>
#include "singly_linked_list.h"

int main() {
    SinglyLinkedList<int> list;
    list.insertFront(10);
    list.insertBack(20);
    list.insertBack(30);
    list.remove(20);

    list.traverse([](int value) {
        std::cout << value << " ";
    }); // Output: 10 30

    return 0;
}
```

## API Reference

- `void insertFront(const T& value);` – Insert an element at the front.
- `void insertBack(const T& value);` – Insert an element at the back.
- `bool remove(const T& value);` – Remove the first occurrence of value.
- `bool contains(const T& value) const;` – Check if a value exists in the list.
- `void traverse(std::function<void(const T&)> func) const;` – Apply a function to each element.

## Building & Testing

If provided, tests can be built and run using a C++ compiler. Example using g++:

```bash
g++ -std=c++11 test_singly_linked_list.cpp -o test_list
./test_list
```

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License.

---

*Created by [TareqAlKushari](https://github.com/TareqAlKushari)*
