# Multi-Function Calculator — C++

A menu-driven calculator supporting multiple modes: averaging, number formatting, random number generation, quadratic root-solving, sorting, and saving results to a file.

## What it does

- **[A] Average** — averages a user-specified count of numbers
- **[F] Formatting** — displays a number in fixed or scientific notation with an adjustable number of decimal places
- **[R] Random** — generates a random number
- **[Q] Quadratic root solving** — solves for both roots of a quadratic equation using a dedicated `Root` class
- **[O] Organize** — sorts 5 user-entered numbers in ascending order using bubble sort, displayed via pointer arithmetic
- **[W] Write to file** — saves the most recent result to a local `solution.txt` file
- **[E] Exit**

The calculator remembers the last computed result across modes and is built for extensibility — additional modes (such as unit conversion) can be added following the same menu structure.

## Tools & Language

- **Language:** C++
- Standard library only (`<iostream>`, `<iomanip>`, `<string>`, `<cmath>`, `<cstdlib>`, `<fstream>`)

## How to run

```bash
g++ Calculator.cpp -o calculator
./calculator
```

Follow the on-screen menu to select a mode. Output from the "Write to file" mode is saved as `solution.txt` in the same directory as the executable.

## Background

Built as a cumulative project applying object-oriented design (the `Root` class), pointer arithmetic, file I/O, and menu-driven program structure in C++.
