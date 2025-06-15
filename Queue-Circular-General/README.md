# Queue Circular General

A generic, efficient circular queue (ring buffer) implementation in C++.

## Overview

This repository contains a reusable, template-based circular queue (ring buffer) implementation. A circular queue is a linear data structure that follows the FIFO (First-In-First-Out) principle and efficiently utilizes array space by wrapping around when the end of the array is reached. This makes it ideal for buffering, real-time data streams, and task scheduling.

## Features

- **Template-Based Design:** Works with any data type.
- **Circular Buffer:** Maximizes space utilization by reusing emptied slots.
- **Core Queue Operations:** Includes `enqueue`, `dequeue`, `front`, `isEmpty`, `isFull`, and `size`.
- **Dynamic or Fixed Size:** Easily adjustable capacity.
- **Exception Safety:** Handles overflow and underflow conditions gracefully.
- **Lightweight & Dependency-Free:** No external libraries required.

## Usage

### 1. Clone the repository

```bash
git clone https://github.com/TareqAlKushari/Queue-Circular-General.git
cd Queue-Circular-General
```

### 2. Include the Queue header in your project

```cpp
#include "circular_queue.h"
```

### 3. Example

```cpp
#include <iostream>
#include "circular_queue.h"

int main() {
    CircularQueue<int> q(5); // capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front: " << q.front() << std::endl; // 10

    q.dequeue();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Queue is now full

    while (!q.isEmpty()) {
        std::cout << q.front() << " ";
        q.dequeue();
    }
    // Output: 20 30 40 50 60

    return 0;
}
```

## API Reference

- `void enqueue(const T& value);` – Add an element to the queue.
- `void dequeue();` – Remove the front element from the queue.
- `T& front();` – Access the front element.
- `bool isEmpty() const;` – Check if the queue is empty.
- `bool isFull() const;` – Check if the queue is full.
- `size_t size() const;` – Get the number of elements in the queue.

## Building & Testing

If provided, tests can be built and run using a C++ compiler. Example using g++:

```bash
g++ -std=c++11 test_circular_queue.cpp -o test_queue
./test_queue
```

## Contributing

Contributions are welcome! Please open an issue or submit a pull request.

## License

This project is licensed under the MIT License.

---

*Created by [TareqAlKushari](https://github.com/TareqAlKushari)*
