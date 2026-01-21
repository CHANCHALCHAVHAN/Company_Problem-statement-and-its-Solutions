/*
Problem Statement
In a busy urban delivery depot, there are N delivery bikes, each having two tires. Each tire is identified by its wear level, represented as an integer from 0 to 100:

0 means brand new

100 means completely worn out

A tire is considered safe if its wear level is ≤ T, where T is the maximum tolerable wear before it becomes dangerous.

The depot manager wants to maximize the number of bikes that can be sent out for deliveries. A bike is considered eligible for delivery if at least one of its two tires is safe (i.e., wear level ≤ T). If both tires are worn out beyond T, the bike must be sent for maintenance.

Your job is to compute the maximum number of bikes that can be sent out without replacing any tires.

Input Format
First line contains two integers: N and T.

Next N lines each contain two integers A[i] and B[i]

Output Format
Print the number of bikes eligible for delivery.

Constraints
1 ≤ N ≤ 10^5

0 ≤ T ≤ 100

0 ≤ A[i], B[i] ≤ 100

Sample Testcase 0
Testcase Input
4 80
60 70
20 30
40 80
80 80
Testcase Output
4
Explanation
All bikes have at least one (or both) tires ≤ 80 → All Valid
Bikes: All → Total: 4


Output: 4

Sample Testcase 1
Testcase Input
5 50
20 90
60 51
90 30
100 40
80 60
Testcase Output
3
Explanation
Bike 1: 20 is safe → Valid


Bike 2: both > 50 → Invalid


Bike 3: 30 is safe → Valid


Bike 4: 40 is safe → Valid


Bike 5: both > 50 → Invalid
Bikes: 1, 3, 4 → Total: 3


Output: 3

Companies
Topics
Array
Greedy
Simulation
Algorithms, Implementation
Filtering
Data Structure
Greedy Algorithms
Suggested Questions
*/
#include <stdio.h>

// Function to count eligible bikes
int countEligibleBikes(int tyres[][2], int N, int T) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        // A bike is eligible if at least one tyre is safe
        if (tyres[i][0] <= T || tyres[i][1] <= T) {
            count++;
        }
    }

    return count;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    int tyres[N][2];

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &tyres[i][0], &tyres[i][1]);
    }

    int result = countEligibleBikes(tyres, N, T);
    printf("%d\n", result);

    return 0;
}
