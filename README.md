# Simple Multithreader

Simple Multithreader is a C++ library that provides a basic interface for parallelizing loops using Pthreads. It includes functions for parallelizing a one-dimensional loop (`parallel_for`) and a two-dimensional loop (`parallel_for` for matrix multiplication). The library utilizes C++11 lambda functions to define the loop body that will be executed in parallel.

## Table of Contents
- [Usage](#usage)
  - [1D Parallelization](#1d-parallelization)
  - [2D Parallelization](#2d-parallelization)
- [Building and Running](#building-and-running)
- [Example Applications](#example-applications)
- [License](#license)

## Usage

### 1D Parallelization

The `parallel_for` function is used for parallelizing a one-dimensional loop. It takes the loop range (`low` and `high`), a lambda function representing the loop body, and the number of threads to use.

```cpp
parallel_for(0, size, [&](int i) {
  // Loop body logic here
}, numThreads);
```

### 2D Parallelization

For parallelizing two-dimensional loops (e.g., matrix multiplication), the `parallel_for` function is used with additional parameters for the outer and inner loop ranges.

```cpp
parallel_for(0, size, 0, size, [&](int i, int j) {
  // Loop body logic here
}, numThreads);
```

## Building and Running
Prerequisite: 
```
sudo apt install make
```
To build the code, compile it with a C++ compiler. For example:


```bash
make all
```

To run the application:

```bash
./file_name [numThreads] [size]
```

- `numThreads`: Number of threads to use (optional, default is 2).
- `size`: Size of the problem (optional, default is 1024).

## Example Applications

### Vector Addition

The `file_name.cpp` file includes an example of parallel vector addition.

```cpp
#include "simple-multithreader.h"
#include <assert.h>

int main(int argc, char** argv) {
  // Initialize problem size and number of threads
  int numThreads = argc > 1 ? atoi(argv[1]) : 2;
  int size = argc > 2 ? atoi(argv[2]) : 48000000;  

  // ... (rest of the code)

  return 0;
}
```

### Matrix Multiplication

The `main.cpp` file also includes an example of parallel matrix multiplication.

```cpp
#include "simple-multithreader.h"
#include <assert.h>

int main(int argc, char** argv) {
  // Initialize problem size and number of threads
  int numThreads = argc > 1 ? atoi(argv[1]) : 2;
  int size = argc > 2 ? atoi(argv[2]) : 1024;  

  // ... (rest of the code)

  return 0;
}
```
# Parallel Multithreading Library

## Contributors:
- Pranav Tanwar
- Namit Jain

## Contribution Division:

### Pranav Tanwar(2022368):
1. Implemented the `thread_func` function for single-threaded execution.
2. Created the `parallel_for` function for one-dimensional parallelization.
3. Assisted in testing and debugging the single-threaded and one-dimensional parallelization functionalities.

### Namit Jain(2022315):
1. Implemented the `thread_func_2` function for two-dimensional parallelized execution.
2. Developed the `parallel_for` function for two-dimensional parallelization.
3. Collaborated in optimizing the code and improving overall performance.
4. Assisted in preparing the documentation and README file.



## GitHub Repository Link:

https://github.com/namit22315/assignment_5_group_67