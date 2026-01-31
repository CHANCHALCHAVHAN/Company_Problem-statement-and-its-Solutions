/*
Problem Statement
In a village, there is a single area that accommodates only K worshippers at a time. During an occasion, the number of people wanting to offer prayer has increased significantly.

There are N villagers, and each has a personal prayer time window [start_i, end_i] in minutes from midnight (0 to 1439), during which they prefer to pray. Each prayer takes exactly T minutes, and a villager can only pray once per day.

Due to health protocols, no two villagers can overlap in the same prayer slot, and only up to K people can pray in parallel at any time.

You need to assign time slots to as many villagers as possible such that:

A villager is assigned a slot fully within their preferred window.

The slot is of length exactly T.

No time unit (minute) is occupied by more than K people.

Your task is to calculate the maximum number of villagers who can be assigned valid, non-conflicting prayer slots.

Input Format
First line contains three integers N, K, and T.
Next N lines: Each line contains two integers start_i and end_i.

Output Format
Print the maximum number of villagers that can be assigned a valid slot.

Constraints
1 <= N <= 1000  
1 <= K <= 50  
1 <= T <= 60  
0 <= start_i < end_i <= 1439  
(end_i - start_i) >= T

Sample Testcase 0
Testcase Input
3 1 15
10 50
20 60
30 70
Testcase Output
3
Explanation
K = 1 (only one person can pray at any minute)


T = 15 minutes


Try assigning earliest possible valid 15-minute slots:


Villager 1: 10–25 Valid


Villager 2: 25–40 Valid (doesn’t overlap with 10–25)


Villager 3: 40–55 Valid


None of the slots overlap. So, all 3 villagers can pray.

Sample Testcase 1
Testcase Input
4 1 10
0 20
5 25
10 30
15 35
Testcase Output
3
Explanation
K = 1 → only one person can pray at any minute


T = 10 minutes


Try assigning:


V1: 0–10 Valid


V2: 10–20 Valid


V3: 20–30 Valid


V4: earliest possible is 15–25 Invalid overlaps with V3


Only 3 villagers can be assigned without exceeding K.

Companies
Topics
Greedy
Scheduling
Interval Problems
Resource Allocation
Simulation
Heap (Priority Queue)
Optimization
Greedy Algorithms
*/
import java.util.*;

class Villager {
    int start;
    int end;

    Villager(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

public class Main {

    public static int maxVillagers(int N, int K, int T, Villager[] villagers) {

        // Sort villagers by earliest end time
        Arrays.sort(villagers, Comparator.comparingInt(v -> v.end));

        // used[m] = number of villagers praying at minute m
        int[] used = new int[1440];

        int count = 0;

        for (Villager v : villagers) {

            // Try all possible start times inside [start, end - T]
            for (int s = v.start; s + T <= v.end; s++) {
                boolean canAssign = true;

                // Check capacity for all T minutes
                for (int m = s; m < s + T; m++) {
                    if (used[m] >= K) {
                        canAssign = false;
                        break;
                    }
                }

                // Assign if feasible
                if (canAssign) {
                    for (int m = s; m < s + T; m++) {
                        used[m]++;
                    }
                    count++;
                    break; // move to next villager
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int T = scanner.nextInt();

        Villager[] villagers = new Villager[N];
        for (int i = 0; i < N; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            villagers[i] = new Villager(start, end);
        }

        System.out.println(maxVillagers(N, K, T, villagers));
    }
}
