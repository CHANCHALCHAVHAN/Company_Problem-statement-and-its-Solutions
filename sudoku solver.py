"""
Problem Statement
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Note: It is guaranteed that the input board has only one solution.

Input Format
For each of the 9 lines of input every line constains 9 characters in the sudoku, a number indicates that that position contains a number. And a dot indicates an empty position.

Output Format
Solve and output the valid solution of the given sudoku problem

Constraints
board.length == 9

board[i].length == 9

board[i][j] is a digit or '.'.

Sample Testcase 0
Testcase Input
. 4 . . . . 2 . .
. . . . . . . 8 .
. . . 2 8 . 7 . 4
8 5 9 4 . . . . .
. 1 . . 6 . 5 . .
6 . . 9 . 5 4 . .
7 9 . . . 2 . . .
. . 3 . 7 1 . . 6
. . 1 6 . 3 . . .
Testcase Output
3 4 8 7 5 6 2 9 1
9 7 2 1 3 4 6 8 5
1 6 5 2 8 9 7 3 4
8 5 9 4 1 7 3 6 2
2 1 4 3 6 8 5 7 9
6 3 7 9 2 5 4 1 8
7 9 6 8 4 2 1 5 3
4 8 3 5 7 1 9 2 6
5 2 1 6 9 3 8 4 7
Explanation
The input grid contains some pre-filled cells and some empty cells (.). The goal is to fill in the empty cells such that:
Each row has the digits 1 through 9 exactly once.
Each column has the digits 1 through 9 exactly once.
Each 3x3 sub-grid contains the digits 1 through 9 exactly once.


This grid is designed to be solved using Sudoku solving techniques.

Sample Testcase 1
Testcase Input
. 5 3 2 . 7 . . 8
6 . 1 5 . . . . 2
2 . . 9 1 3 . 5 .
7 1 4 6 9 2 . . .
. 2 . . . . . 6 .
. . . 4 5 1 2 9 7
. 6 . 3 2 5 . . 9
1 . . . . 6 3 . 4
8 . . 1 . 9 6 7 .
Testcase Output
9 5 3 2 6 7 1 4 8
6 7 1 5 8 4 9 3 2
2 4 8 9 1 3 7 5 6
7 1 4 6 9 2 5 8 3
5 2 9 7 3 8 4 6 1
3 8 6 4 5 1 2 9 7
4 6 7 3 2 5 8 1 9
1 9 5 8 7 6 3 2 4
8 3 2 1 4 9 6 7 5
Explanation
The provided input is a partially filled Sudoku grid, where . represents empty cells that need to be filled according to Sudoku rules. The goal is to complete the grid so that:
Each row contains the digits 1 through 9 exactly once.
Each column contains the digits 1 through 9 exactly once.
Each 3x3 sub-grid (box) contains the digits 1 through 9 exactly once.

Companies
DoorDash
Intuit
Nutanix
Topics
Recursion
Backtracking
Matrix


"""
#CODE 

# Sudoku solver (reads 9 lines, '.' for empty)
# Uses backtracking with bitmasks for speed.

import sys

def read_board():
    board = []
    for _ in range(9):
        line = sys.stdin.readline().strip()
        if not line:
            # if blank line, try again (robustness)
            line = sys.stdin.readline().strip()
        parts = line.split()
        if len(parts) == 9:
            row = parts
        else:
            # remove spaces and take characters
            s = line.replace(" ", "")
            if len(s) != 9:
                raise ValueError("Each input line must contain 9 characters (digits or '.')")
            row = list(s)
        board.append(row)
    return board

def solve_sudoku(board):
    # bitmasks for rows, cols, boxes: bit d (1<<d) means digit d used (d in 1..9)
    rows = [0]*9
    cols = [0]*9
    boxes = [0]*9
    empties = []

    def box_index(r, c):
        return (r//3)*3 + (c//3)

    # initialize masks and collect empty cells
    for r in range(9):
        for c in range(9):
            ch = board[r][c]
            if ch == '.':
                empties.append((r,c))
            else:
                d = int(ch)
                bit = 1 << d
                rows[r] |= bit
                cols[c] |= bit
                boxes[box_index(r,c)] |= bit

    # backtracking with ordering: we'll try empties in given order
    n = len(empties)

    def backtrack(idx=0):
        if idx == n:
            return True
        # Optional optimization: choose the empty with fewest candidates (MRV)
        # We'll implement MRV lookup each step for better performance on hard puzzles.
        best_i = -1
        best_count = 10
        for i in range(idx, n):
            r, c = empties[i]
            used = rows[r] | cols[c] | boxes[box_index(r,c)]
            candidates = 0
            # count available digits
            for d in range(1,10):
                if not (used & (1<<d)):
                    candidates += 1
            if candidates < best_count:
                best_count = candidates
                best_i = i
                if best_count == 1:
                    break
        # swap chosen into position idx
        empties[idx], empties[best_i] = empties[best_i], empties[idx]
        r, c = empties[idx]
        used = rows[r] | cols[c] | boxes[box_index(r,c)]
        for d in range(1,10):
            bit = 1 << d
            if used & bit:
                continue
            # place d
            board[r][c] = str(d)
            rows[r] |= bit
            cols[c] |= bit
            boxes[box_index(r,c)] |= bit
            if backtrack(idx+1):
                return True
            # undo
            board[r][c] = '.'
            rows[r] &= ~bit
            cols[c] &= ~bit
            boxes[box_index(r,c)] &= ~bit
        # swap back (optional)
        empties[idx], empties[best_i] = empties[best_i], empties[idx]
        return False

    success = backtrack(0)
    return success

def print_board(board):
    for r in range(9):
        print(" ".join(board[r]))

if __name__ == "__main__":
    board = read_board()
    if solve_sudoku(board):
        print_board(board)
    else:
        print("No solution exists", file=sys.stderr)
