## Sudoku-Solver
Sudoku solvers for solving Sudoku and counting the number of solutions, implemented using C++, MiniSat, Python, and PyEDA.

The solver transforms Sudoku problem into boolean formula in conjunctive normal form, and use Minisat to find a feasible solution and PyEDA to find the total number of solutions.

## How to Run
### Solving Sudoku
Download [MiniSat_v1.14](http://minisat.se/downloads/MiniSat_v1.14.2006-Aug-29.src.zip) from [MiniSat official website](http://minisat.se/MiniSat.html).
Generate a statically linked release version of MiniSat.
```
make rs
```
An executable named `minisat_static` will be generated.

Compile solver source code.
```
g++ -o solver solver.cpp
```

Create a Sudoku puzzle. For example, a text file named `example_9x9.in` with the following content.
```
3 4 0 0 0 0 0 0 0
0 0 0 7 0 3 8 1 2
0 2 0 0 0 5 9 0 0
0 8 0 1 0 0 0 2 3
4 0 0 0 0 0 0 0 6
9 0 0 3 6 0 0 0 0
0 0 0 9 0 0 0 0 0
0 0 5 0 0 1 7 4 0
2 0 7 0 8 0 0 5 0
```
0's in the Sudoku puzzle indicate empty cells.

### Counting the Number of Solutions


