# int2025_t

__int2025_t__ is a C++23 library for a configurable fixed-width signed integer.

## Features
- Convertation from `int32_t` (`from_int`).
- Convertation from a signed decimal C string (`from_string`).
- Addition (`operator+`).
- Substraction (`operator-`).
- Multiplication (`operator*`).
- Division (`operator/`).
- Comparisons (`operator==`, `operator!=`, `operator<`, `operator<=`, `operator>`, `operator>=`)
- Binary stream output (`operator<<`).

## Specifications

- The default width is 2025 bits.
- The default range is `[-2^2024, 2^2024 - 1]`.
- Two's-complement arithmetics.
- Little-endian byte order.
- Overflow wraps at the last bit.


## Building and testing

Requirements:

- CMake 3.24 or later.
- A C++23 compiler.

Build the project and run the tests:

```sh
cmake -S . -B build
cmake --build build --target int2025_t_tests int2025_t_demo
ctest --test-dir build --output-on-failure
```
Run the demo:

```sh
./build/bin/int2025_t_demo
```