## Sudoku-Solver
Sudoku solvers for solving Sudoku and counting the number of solutions, implemented using C++, MiniSat, Python, and PyEDA.

The solver transforms Sudoku problem into boolean formula in conjunctive normal form, and use Minisat to find a feasible solution and PyEDA to find the total number of solutions.

## How to Run
Create a text file describing a Sudoku puzzle.

For example, a text file with the following content (0's indicate empty cells).
```
0 0 0 3 1 6 5 0 0
8 0 0 5 0 0 1 0 0
0 1 0 8 9 7 2 4 0
9 0 1 0 8 5 0 2 0
0 0 0 9 0 1 0 0 0
0 4 0 2 6 3 0 0 1
0 5 0 0 0 0 0 1 0
1 0 0 4 0 9 0 0 2
0 0 6 1 0 8 0 0 0
```

### Solving Sudoku
Download [MiniSat_v1.14](http://minisat.se/downloads/MiniSat_v1.14.2006-Aug-29.src.zip) from [MiniSat official website](http://minisat.se/Main.html).

Generate a statically linked release version of MiniSat.
```
$ make rs
```
An executable named `minisat_static` will be generated.

Compile solver source code.
```
$ g++ -o solver solver.cpp
```

Run the solver.
```
$ ./solver <Sudoku.in> <Sudoku.out> minisat_static
```
The solver will read from <Sudoku.in> and auto-detect the size of the puzzle.

A feasible solution is written to <Sudoku.out>, which looks like the following.
```
 4  7  2  3  1  6  5  8  9 
 8  6  9  5  2  4  1  3  7 
 3  1  5  8  9  7  2  4  6 
 9  3  1  7  8  5  6  2  4 
 6  2  8  9  4  1  3  7  5 
 5  4  7  2  6  3  8  9  1 
 7  5  4  6  3  2  9  1  8 
 1  8  3  4  5  9  7  6  2 
 2  9  6  1  7  8  4  5  3 
```

### Counting the Number of Solutions
Install [PyEDA](https://pypi.org/project/pyeda/).
```
$ pip3 install pyeda
```

Run the counter.
```
$ python3 <Sudoku.in> <Sudoku.out>
```
The counter will read from <Sudoku.in> and auto-detect the size of the puzzle.

The number of feasible solutions is written to <Sudoku.out>, which looks like the following.
```
125
```

