/*
Problem Statement
You are in charge of a smart dam system that stores water in a sequence of N chambers, arranged in a line from uphill to downhill (indexed from 0 to N-1). Each chamber has two properties:

capacity[i] — the maximum units of water chamber i can hold.
initial[i] — the initial units of water currently stored in chamber i.
Water flows from chamber 0 (uphill) to chamber N-1 (downhill). Your task is to simulate the flow of water sequentially from chamber 0 to N-1.

For each step i (from 0 to N-2):

You transfer all available water from chamber i to chamber i+1.
During the transfer, there is a natural loss: for every X units sent, ceil(X * loss_percent / 100) units are lost (evaporated or leaked).
The remaining water (X - loss) reaches chamber i+1.
If the total water at chamber i+1 (initial + incoming) exceeds its capacity, the excess spills over and is permanently lost.
Your goal is to determine the final amount of water retained in the last chamber (N-1) after the flow reaches the end.

Input Format
First line contains an integer N.

Second line: N space-separated integers — capacity[0..N-1]

Third line: N space-separated integers — initial[0..N-1]

Fourth line contains an integer loss_percent — the percentage of water lost when transferring from one chamber to the next.

Output Format
Print the maximum water that can be retained in the last chamber (N-1) after all optimal possible redistribution.

Constraints
1 <= N <= 10^3 
0 <= capacity[i], initial[i] <= 10^6  
0 <= loss_percent <= 50

Sample Testcase 0
Testcase Input
3
100 100 100
90 0 0
20
Testcase Output
57
Explanation
Water starts at chamber 0 with 90 units.


20% water is lost at each transfer.


Step-by-step:


Chamber 0 → 1:
Send 90 → Loss = ceil(18) → Receive = 72
chamber 1 = 72


Chamber 1 → 2:
Send 72 → Loss = ceil(14.4) = 15 → Receive = 57
chamber 2 = 57


Final Answer: 57

Sample Testcase 1
Testcase Input
5
10 8 6 5 15
10 0 0 0 0
10
Testcase Output
4
Explanation
Initial water: 10 in chamber 0


Water flows from chamber 0 to 4, with 10% loss at each step.


Step-by-step:


Chamber 0 → 1:
Send 10 → Loss = ceil(10 * 10%) = 1
Receive = 9 (capped by chamber 1's capacity 8 → gets 8)
Remaining: chamber 0 = 0, chamber 1 = 8


Chamber 1 → 2:
Send 8 → Loss = ceil(8 * 10%) = 1
Receive = 7 (fits in chamber 2)
chamber 2 = 7


Chamber 2 → 3:
Send 7 → Loss = ceil(7 * 10%) = 1 → Receive = 6
Chamber 3 has capacity 5 → receives only 5
chamber 3 = 5


Chamber 3 → 4:
Send 5 → Loss = ceil(5 * 10%) = 1 → Receive = 4
chamber 4 = 4


Final Answer: 4

Companies
Topics
Greedy Algorithm
Simulation
Math
Prefix Handling
Array
Data Structure
Greedy Algorithms
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> capacity(N), initial(N);
    for(int i = 0; i < N; i++) cin >> capacity[i];
    for(int i = 0; i < N; i++) cin >> initial[i];

    int loss_percent;
    cin >> loss_percent;

    for(int i = 0; i < N - 1; i++) {
        long long water = initial[i];     // send all
        initial[i] = 0;

        if(water == 0) continue;

        long long loss = (water * loss_percent + 99) / 100; // ceil(x * p / 100)
        long long received = water - loss;

        if(received < 0) received = 0;

        initial[i+1] = min(capacity[i+1], initial[i+1] + received);
    }

    cout << initial[N-1];
    return 0;
}
