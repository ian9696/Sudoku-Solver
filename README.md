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

Create a Sudoku puzzle. For example, a text file with the following content.
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

Run the solver.
```
./solver <Sudoku.in> <Sudoku.out>
```
<Sudoku.in> is the Sudoku puzzle.
The Solver will find a solution and write it to <Sudoku.out>, which looks like the following.
```
 3  4  1  8  9  2  6  7  5 
 6  5  9  7  4  3  8  1  2 
 7  2  8  6  1  5  9  3  4 
 5  8  6  1  7  9  4  2  3 
 4  7  3  5  2  8  1  9  6 
 9  1  2  3  6  4  5  8  7 
 1  3  4  9  5  7  2  6  8 
 8  6  5  2  3  1  7  4  9 
 2  9  7  4  8  6  3  5  1 
```

### Counting the Number of Solutions


