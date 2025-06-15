# Queue Circular Dynamic

A flexible, dynamically resizable circular queue (ring buffer) implementation in C++.

## Overview

This repository provides a robust, template-based circular queue (ring buffer) that can grow and shrink in size as needed, unlike static circular buffers with fixed capacities. The dynamic resizing feature makes this queue ideal for scenarios where the number of elements can change significantly at runtime—such as buffering variable-sized data streams or managing tasks in systems with unpredictable loads.

## Features

- **Template-Based:** Works with any data type.
- **Dynamically Resizable:** Automatically expands or contracts to optimize memory use.
- **Circular Buffer:** Efficient space utilization with fast enqueue and dequeue operations.
- **Standard Queue Operations:** Includes `enqueue`, `dequeue`, `front`, `isEmpty`, `size`, and `capacity`.
- **Exception Safety:** Handles overflow and underflow conditions gracefully.
- **Lightweight & Dependency-Free:** No external libraries required.

## Usage

### 1. Clone the repository

```bash
git clone https://github.com/TareqAlKushari/Queue-Circular-Dynamic.git
cd Queue-Circular-Dynamic
```

### 2. Include the queue header in your project

```cpp
#include "dynamic_circular_queue.h"
```

### 3. Example

```cpp
#include <iostream>
#include "dynamic_circular_queue.h"

int main() {
    DynamicCircularQueue<int> q(3); // Initial capacity 3

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Queue grows as new elements are added
    q.enqueue(40);

    std::cout << "Front: " << q.front() << std::endl; // 10

    q.dequeue(); // Remove 10

    while (!q.isEmpty()) {
        std::cout << q.front() << " ";
        q.dequeue();
    }
    // Output: 20 30 40

    return 0;
}
```

## API Reference

- `void enqueue(const T& value);` – Add an element to the queue, expanding the buffer if needed.
- `void dequeue();` – Remove the front element from the queue.
- `T& front();` – Access the front element.
- `bool isEmpty() const;` – Check if the queue is empty.
- `size_t size() const;` – Get the current number of elements.
- `size_t capacity() const;` – Get the current capacity of the queue.

## Building & Testing

If provided, tests can be built and run using a C++ compiler. Example using g++:

```bash
g++ -std=c++11 test_dynamic_circular_queue.cpp -o test_queue
./test_queue
```

## Contributing

Contributions are welcome! Please open an issue or submit a pull request.

## License

This project is licensed under the MIT License.

---

*Created by [TareqAlKushari](https://github.com/TareqAlKushari)*
