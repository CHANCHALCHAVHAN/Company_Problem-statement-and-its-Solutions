/*
Problem Statement
You are playing a digital version of Carrom where there are N coins placed at different positions on a circular board. The board is numbered from 0 to 360 degrees. You are controlling a striker that starts at angle 0 and can be rotated clockwise only.

Each coin is located at a certain angle on the board, and your striker can hit and pocket coins only when the angle of rotation matches the coin’s position. However, the striker requires energy to rotate: 1 unit of energy per degree of rotation.

After hitting a coin, you can move on to the next coin from that position (current angle), continuing clockwise. You must pocket all coins in any order, but always moving in one direction (clockwise).

Your goal is to minimize the total energy used to pocket all the coins.

Input Format
The first line contains a single integer N

The second line contains N space-separated integers A[0], A[1], ..., A[N-1]

Output Format
Print the minimum total energy required to pocket all coins in optimal order.

Constraints
1 ≤ N ≤ 360  
0 ≤ A[i] ≤ 359  
All A[i] are distinct

Sample Testcase 0
Testcase Input
4
30 90 150 270
Testcase Output
270
Explanation
Starting angle = 0


Go to 30 → Energy = 30


30 → 90 → +60


90 → 150 → +60


150 → 270 → +120


Total Energy = 30 + 60 + 60 + 120 = 270

Sample Testcase 1
Testcase Input
5
300 10 90 180 250
Testcase Output
300
Explanation
Sorted Angles: [10, 90, 180, 250, 300]


Explanation:


Start at 0 → 10 → +10


10 → 90 → +80


90 → 180 → +90


180 → 250 → +70


250 → 300 → +50


Total Energy = 10 + 80 + 90 + 70 + 50 = 300

Companies
Topics
Greedy
Sorting
Simulation
Circular Array
Algorithms, Implementation
minimum cost flow
Greedy Algorithms
*/
import java.util.*;

class Main {
    public static int minEnergyToClearCoins(int[] angles) {
        // Sort angles in ascending order
        Arrays.sort(angles);

        int energy = 0;
        int current = 0; // striker starts at 0°

        for (int angle : angles) {
            energy += angle - current; // clockwise difference
            current = angle;
        }

        return energy;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read number of coins

        int[] angles = new int[N];
        for (int i = 0; i < N; i++) {
            angles[i] = scanner.nextInt(); // Read coin positions
        }

        int result = minEnergyToClearCoins(angles);
        System.out.println(result);

        scanner.close();
    }
}
