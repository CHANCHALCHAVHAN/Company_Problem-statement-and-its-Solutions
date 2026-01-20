/*
Problem Statement
You are given a 2D grid of size N x M. Each cell of the grid contains a color represented by a lowercase English letter ('a' to 'z').

You start at the top-left corner (0, 0) and want to reach the bottom-right corner (N-1, M-1) by moving only right or down at each step.

A path's color sequence is the sequence of colors of the cells visited along the path.

Your task is to find the number of distinct color sequences that can be formed by any valid path from (0, 0) to (N-1, M-1).

Since the number can be very large, output the count modulo 10^9 + 7.

Input Format
The first line contains two integers N and M 

Each of the next N lines contains a string of length M, representing the grid colors.

Output Format
Print the number of distinct color sequences modulo 10^9 + 7.

Constraints
1 ≤ N, M ≤ 10

Sample Testcase 0
Testcase Input
2 2
ab
cd
Testcase Output
2
Explanation
Grid:
a b
c d


All valid paths from (0, 0) to (1, 1):


a → b → d → "abd"


a → c → d → "acd"

There are exactly 2 valid paths each resulting in a unique color sequence ("abd", "acd").


Output: 2

Sample Testcase 1
Testcase Input
3 3
abc
def
ghi
Testcase Output
6
Explanation
Grid:
a b c
d e f
g h i


Total paths = C(4,2) = 6 paths


List of all distinct sequences (by enumerating all 6 paths):


a → b → c → f → i → "abcfi"


a → b → e → f → i → "abefi"


a → d → e → f → i → "adefi"


a → d → g → h → i → "adghi"


a → b → e → h → i → "abehj"


a → d → e → h → i → "adehi"


(Note: Actual sequences may vary based on path direction, ensure your implementation follows correct DFS with down/right only)


Each of the 6 paths leads to a unique sequence, so the result is 6.


Output: 6

Companies
Topics
Dynamic Programming
Grid Traversal
String
Hashing
Combinatorics
Memoization
Grid
*/
import java.util.*;

public class Main {
    static final int MOD = 1000000007;
    static Set<String> set;
    static int N, M;
    static char[][] mat;

    public static int countDistinctColorSequences(int n, int m, String[] grid) {
        N = n;
        M = m;

        mat = new char[N][M];
        for (int i = 0; i < N; i++) {
            mat[i] = grid[i].toCharArray();
        }

        set = new HashSet<>();
        dfs(0, 0, new StringBuilder());

        return set.size() % MOD;
    }

    private static void dfs(int i, int j, StringBuilder path) {
        path.append(mat[i][j]);

        if (i == N - 1 && j == M - 1) {
            set.add(path.toString());
        } else {
            if (j + 1 < M) {
                dfs(i, j + 1, path);
            }
            if (i + 1 < N) {
                dfs(i + 1, j, path);
            }
        }

        // backtrack
        path.deleteCharAt(path.length() - 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        String[] grid = new String[N];
        for (int i = 0; i < N; i++) {
            grid[i] = scanner.nextLine();
        }

        int result = countDistinctColorSequences(N, M, grid);
        System.out.println(result);
    }
}
