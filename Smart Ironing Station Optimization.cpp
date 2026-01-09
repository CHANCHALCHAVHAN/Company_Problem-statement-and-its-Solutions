/*
Problem Statement
You run a smart ironing station that uses a robotic iron to press clothes placed on a conveyor belt. The iron can press a cloth in exactly 1 time unit, but it takes additional time to adjust its temperature based on the fabric type of the next cloth in line.

Each cloth has a fabric type represented by an integer f[i] and a required temperature represented by t[i]. If the previous cloth had the same fabric type, no temperature adjustment is needed. But if the fabric changes, it takes |t[i] - t[i-1]| time units to adjust the iron before it can press the cloth.

Your task is to compute the minimum total time required to press all N clothes placed in a given sequence on the belt.

Input Format
First line contains an integer N.

Second line contains N space-separated integers f[0] f[1] ... f[N-1].

Third line contains N space-separated integers t[0] t[1] ... t[N-1].

Output Format
Print the total time (in units) required to press all clothes.

Constraints
1 <= N <= 10^5

1 <= f[i] <= 1000

0 <= t[i] <= 300

Sample Testcase 0
Testcase Input
4
1 1 1 1
100 100 100 100
Testcase Output
4
Explanation
Cloth 0: First cloth → +1


Cloth 1: Same fabric → +1


Cloth 2: Same fabric → +1


Cloth 3: Same fabric → +1
Total = 1 + 1 + 1 + 1 = 4

Sample Testcase 1
Testcase Input
5
1 1 2 2 1
100 100 150 150 90
Testcase Output
115
Explanation
Cloth 0: First cloth → +1


Cloth 1: Same fabric → +1


Cloth 2: Fabric changed → |150 - 100| = 50 → +50 +1 = 51


Cloth 3: Same fabric → +1


Cloth 4: Fabric changed → |90 - 150| = 60 → +60 +1 = 61
Total = 1 + 1 + 51 + 1 + 61 = 115

Companies
Topics
Simulation
Greedy
Array
Data Structure
simulation
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> f(N), t(N);
    for (int i = 0; i < N; i++) cin >> f[i];
    for (int i = 0; i < N; i++) cin >> t[i];

    long long totalTime = 1; // first cloth

    for (int i = 1; i < N; i++) {
        totalTime += 1; // pressing time
        if (f[i] != f[i - 1]) {
            totalTime += abs(t[i] - t[i - 1]);
        }
    }

    cout << totalTime << "\n";
    return 0;
}
