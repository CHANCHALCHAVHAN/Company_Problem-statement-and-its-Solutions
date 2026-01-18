/*
Problem Statement
You are given a 2D grid of size N x M representing a city. Each cell contains either:

'0' → an empty land

'B' → a bomb

'W' → a wall

When a bomb ('B') detonates, it destroys all empty land ('0') cells in its row and column, unless blocked by a wall ('W'). A bomb does not destroy walls or other bombs. Walls block the blast in all directions.

Your task is to determine how many safe empty cells ('0') remain after all bombs have detonated simultaneously.

Input Format
First line contains two integers N and M

Next N lines: A string of length M consisting of '0', 'B', or 'W'.

Output Format
Print the number of '0' cells that remain undestroyed after all bomb blasts.

Constraints
1 <= N, M <= 500

Grid contains only '0', 'B', and 'W'

Sample Testcase 0
Testcase Input
3 3
000
0B0
000
Testcase Output
4
Explanation
Bomb at (1,1):


Row → destroys (1,0), (1,2)


Column → destroys (0,1), (2,1)


Destroyed: (1,0), (1,2), (0,1), (2,1)
Total 0 cells = 8
Safe = 8 - 4 = 4

Sample Testcase 1
Testcase Input
3 3
000
000
000
Testcase Output
9
Explanation
There are no bombs (B) and no walls (W).


All cells are '0', and none are affected.


Total safe cells = 9

Companies
Topics
Matrix
Grid Traversal
Simulation
Boolean Operations
Data Structure
Matrix
*/








import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read dimensions
        int N = sc.nextInt();
        int M = sc.nextInt();
        sc.nextLine(); // consume leftover newline

        // Read grid
        char[][] grid = new char[N][M];
        for (int i = 0; i < N; i++) {
            grid[i] = sc.nextLine().toCharArray();
        }

        // Track destroyed cells
        boolean[][] destroyed = new boolean[N][M];

        // Row-wise: Left -> Right
        for (int i = 0; i < N; i++) {
            boolean activeBomb = false;
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 'W') activeBomb = false;
                else if (grid[i][j] == 'B') activeBomb = true;
                else if (grid[i][j] == '0' && activeBomb) destroyed[i][j] = true;
            }
        }

        // Row-wise: Right -> Left
        for (int i = 0; i < N; i++) {
            boolean activeBomb = false;
            for (int j = M - 1; j >= 0; j--) {
                if (grid[i][j] == 'W') activeBomb = false;
                else if (grid[i][j] == 'B') activeBomb = true;
                else if (grid[i][j] == '0' && activeBomb) destroyed[i][j] = true;
            }
        }

        // Column-wise: Top -> Bottom
        for (int j = 0; j < M; j++) {
            boolean activeBomb = false;
            for (int i = 0; i < N; i++) {
                if (grid[i][j] == 'W') activeBomb = false;
                else if (grid[i][j] == 'B') activeBomb = true;
                else if (grid[i][j] == '0' && activeBomb) destroyed[i][j] = true;
            }
        }

        // Column-wise: Bottom -> Top
        for (int j = 0; j < M; j++) {
            boolean activeBomb = false;
            for (int i = N - 1; i >= 0; i--) {
                if (grid[i][j] == 'W') activeBomb = false;
                else if (grid[i][j] == 'B') activeBomb = true;
                else if (grid[i][j] == '0' && activeBomb) destroyed[i][j] = true;
            }
        }

        // Count safe cells
        int safeCells = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '0' && !destroyed[i][j]) {
                    safeCells++;
                }
            }
        }

        // Output result
        System.out.println(safeCells);

        sc.close();
    }
}
