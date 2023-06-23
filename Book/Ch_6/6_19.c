/*
Auth: Muhammad Nabil Akhtar Raya Amoriza | 5025221021
Problem: The eight-queens problem can be stated as follows: place 8 queens on a chess board so that \
no two queens attack each other. Two queens attack each other if they are in the same row, same     \
column, or same diagonal. Clearly, any solution must have the queens in different rows and          \
different columns.
One approach to solving the problem is as follows. Place the first queen in the first column of the \
first row. Next, place the second queen so that it does not attack the first. If this is not        \
possible, go back and place the first queen in the next column and try again. 
After the first two queens have been placed, place the third queen so that it does not attack the   \
first two. If this is not possible, go back and place the second queen in the next column and try   \
again.
At each step, try to place the next queen so that it does not conflict with those already placed.   \
If you succeed, try to place the next queen. If you fail, you must backtrack to the previously      \
placed queen and try the next possible column. If all columns have been tried, you must backtrack   \
to the queen before this queen and try the next column for that queen.
The idea is similar to finding a path through a maze. Write a program to solve the eight-queens     \
problem. Use recursion to implement the backtracking.
*/

#include <stdio.h>
#include <stdbool.h>
#define t printf("test\n");
 
const int ans = 8;
int board[9][9];

void init() {
    for (int i = 0; i < ans; i++)
        for (int j = 0; j < ans; j++)
            board[i][j] = 0;
}
 
bool is_safe(int r, int c) {
    // t
    // checks horizontal
    for (int x = 0; x < c; x++)
        if (board[r][x] == 1)
            return false;
    // checks diagonal
    for (int x = r, y = c; x >= 0 && y >= 0; x--, y--)
        if (board[x][y] == 1)
            return false;
    // checks antidiagonal
    for (int x = r, y = c; x < ans && y >= 0; x++, y--)
        if (board[x][y] == 1)
            return false;
    
    return true;
}
 
bool solve_queens(int c) {
    // t
    // immediately exits if requirements are met
    if (c == ans) {
        for (int i = 0; i < ans; i++) {
            for (int j = 0; j < ans; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
        printf("\n");
        return true;
    }
    // t
    // tries to place a queen in each row
    for (int i = 0; i < ans; i++) {
        if (is_safe(i, c)) {
            board[i][c] = 1;
            if (solve_queens(c + 1))
                return true;
            board[i][c] = 0;
        }
    }
    return false;
}
 
int main(int argc, char const *argv[]) {
    init();
    if (!solve_queens(0))
        printf("Failed\n");
    return 0;
}