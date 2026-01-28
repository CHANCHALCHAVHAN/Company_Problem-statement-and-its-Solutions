/*
Problem Statement
An archaeologist has discovered a large underground maze filled with magical runes and dangerous traps. The maze is represented as a 2D grid of size N x M, where each cell contains a single character rune (from 'A' to 'Z').

The archaeologist must traverse the maze starting from any cell that contains the first character of a secret pattern word, and try to find a complete path that forms the pattern by moving to adjacent cells (up, down, left, right). The rule is:

Each cell may only be used once in a single pattern match.

Multiple pattern paths may exist; your task is to count how many distinct complete paths exist in the grid that form the given pattern.

Write a program to calculate the total number of such distinct paths that exactly match the given pattern.

Input Format
First line contains two integers N and M — the number of rows and columns in the grid.
Next N lines each contain M uppercase letters — the grid itself.
Last line contains a string P — the pattern to be matched.
Output Format
Print a single integer — the total number of distinct complete paths that match the pattern exactly.
Constraints
1 <= N , M <=10 

1 <= P.length() <=10

values in grid or in P string are upper case English letters 

Sample Testcase 0
Testcase Input
2 2
AA
AA
AAA
Testcase Output
8
Explanation
Total paths found:


From (0,0) - (0,1) - (1,1), (0,0) - (1,0) - (1,1): 2
 From (0,1) - (1,1) - (1,0), (0,1) - (0,0) - (1,0): 2
 From (1,0) - (1,1) - (0,1), (1,0) - (0,0) - (0,1): 2
 From (1,1) - (0,1) - (0,0), (1,1) - (1,0) - (0,0): 2


Total = 8 paths

Sample Testcase 1
Testcase Input
3 4
ABCD
AXYD
AXYD
AXY
Testcase Output
2
Explanation
Total paths found:


From (1,0) - (1,1) - (1,2): 1
From (2,0) - (2,1) - (2,2): 1


Total = 2 paths

Companies
Topics
Graph Traversal- DFS
BFS
Patterns
Graphs, DFS, Observation
*/
import java.util.*;

public class Main {

    static int n, m;
    static String[] grid;
    static String pattern;
    static boolean[][] visited;
    static int count = 0;

    // Directions: up, down, left, right
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static int countPatternPaths(String[] g, String p) {
        grid = g;
        pattern = p;
        n = grid.length;
        m = grid[0].length();
        visited = new boolean[n][m];
        count = 0;

        // Start DFS from every cell matching first character
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i].charAt(j) == pattern.charAt(0)) {
                    dfs(i, j, 0);
                }
            }
        }
        return count;
    }

    static void dfs(int x, int y, int idx) {
        // If full pattern matched
        if (idx == pattern.length() - 1) {
            count++;
            return;
        }

        visited[x][y] = true;

        // Explore 4 directions
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                !visited[nx][ny] &&
                grid[nx].charAt(ny) == pattern.charAt(idx + 1)) {

                dfs(nx, ny, idx + 1);
            }
        }

        // Backtrack
        visited[x][y] = false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine();

        String[] grid = new String[n];
        for (int i = 0; i < n; i++) {
            grid[i] = scanner.nextLine();
        }

        String pattern = scanner.nextLine();
        System.out.println(countPatternPaths(grid, pattern));
    }
}
