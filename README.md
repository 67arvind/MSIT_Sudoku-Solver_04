# SudokuSolver

SudokuSolver is a C program that automatically solves Sudoku puzzles. It takes an input grid representing an unsolved Sudoku puzzle and uses backtracking or other suitable techniques to explore possible solutions and find the correct arrangement of numbers.

## Features

- Solves Sudoku puzzles using efficient algorithms
- Takes an unsolved Sudoku grid as input
- Outputs the solved Sudoku grid
- Uses backtracking or other suitable techniques for solving

## Requirements

- C compiler (e.g., GCC)
- Standard C libraries

## Usage

1. Clone the repository:
    ```
    git clone https://github.com/yourusername/SudokuSolver.git
    ```

2. Navigate to the repository directory:
    ```
    cd SudokuSolver
    ```

3. Compile the program:
    ```
    gcc -o SudokuSolver SudokuSolver.c
    ```

4. Run the program with an input file containing the unsolved Sudoku grid:
    ```
    ./SudokuSolver input.txt
    ```

5. The solved Sudoku grid will be displayed on the console.

## Input Format

The input file should contain a 9x9 grid representing the Sudoku puzzle. Each number should be separated by a space, and empty cells should be represented by 0.

Example :-
 3 0 0 7 0 0 0 0 6 0 0 1 9 5 0 0 0 0 9 8 0 0 0 0 6 0 8 0 0 0 6 0 0 0 3 4 0 0 8 0 3 0 0 1 7 0 0 0 2 0 0 0 6 0 6 0 0 0 0 2 8 0 0 0 0 4 1 9 0 0 5 0 0 0 0 8 0 0 7 9
 
