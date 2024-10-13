#include <stdio.h>

#define SIZE 9

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%2d", grid[row][col]);
        }
        printf("\n");
    }
}

// Check if it's safe to place a number at the given row, col
int isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check the row and column
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return 0;
        }
    }

    // Check the 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Backtracking function to solve the Sudoku
int solveSudoku(int grid[SIZE][SIZE]) {
    int row, col, foundEmpty = 0;

    // Find an empty cell (denoted by 0)
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                foundEmpty = 1;
                break;
            }
        }
        if (foundEmpty) break;
    }

    // If no empty cell is found, the puzzle is solved
    if (!foundEmpty) return 1;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;  // Place the number

            // Recur to solve the rest of the grid
            if (solveSudoku(grid)) return 1;

            grid[row][col] = 0;  // Undo the placement (backtrack)
        }
    }
    return 0;  // Trigger backtracking
}

int main() {
    // Input Sudoku grid (0 denotes empty cells)
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        printf("Solved Sudoku grid:\n");
        printGrid(grid);
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}


