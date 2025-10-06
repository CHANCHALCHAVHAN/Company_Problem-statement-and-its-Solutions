/*************************************************************************************************************************************************************************************************************************************************************************************
Problem Statement
A building has N rooms, each with a smart air conditioner that can operate in three modes:

0 = Off

1 = Eco mode (uses 1 unit of energy/hour)

2 = Cool mode (uses 2 units of energy/hour)

The building is active for T hours in a day. For each room, the building manager provides:

A list of cooling requirement intervals. Each interval means the AC must be on (mode 1 or 2) during that time (inclusive).

A maximum energy limit Eᵢ for the AC in that room for the whole day.

You need to generate a valid hourly schedule (list of length T with values 0, 1, or 2) for each room such that:

All required intervals K are covered (AC must not be in mode 0 during those hours).

The total energy consumption does not exceed Eᵢ for each room.

Try to use Cool mode (mode 2) as less frequently as possible (Eco mode is preferred if both satisfy condition 1 and 2).

If it's not possible to fulfill these conditions for any room, output "NOT POSSIBLE" for that room.

Input Format
First line contains two integers N and T.
Next N blocks:
First line of block: Integer K (number of required intervals) and integer Eᵢ (energy limit for this room)
Next K lines: Two integers L and R (required AC interval from hour L to R, inclusive)

Output Format
If a schedule is possible, print a line with T space-separated integers (AC mode for each hour)

Else print: NOT POSSIBLE

Constraints
1 ≤ N ≤ 100

1 ≤ T ≤ 24

1 ≤ K ≤ 10

1 ≤ L ≤ R ≤ T

1 ≤ Eᵢ ≤ 2*T

Sample Testcase 0
Testcase Input
1 6
2 4
1 2
4 5
Testcase Output
1 1 0 1 1 0
Explanation
1 room, 6 hours in a day.


Required intervals: [1–2] and [4–5] → AC must be ON at hours 1, 2, 4, 5.


Energy limit = 4.


Assign Eco mode (1) for hours 1, 2, 4, 5 → Energy = 4.


Valid, within limit.


Output: 1 1 0 1 1 0

Sample Testcase 1
Testcase Input
1 5
1 2
2 4
Testcase Output
NOT POSSIBLE
Explanation
1 room, 5 hours total.


Required interval: [2–4] → AC must be ON at hours 2, 3, 4.


Need to be ON for 3 hours minimum.


Eco mode needs 3 units of energy, but we only have 2 units → Not enough.


No way to reduce further using Cool mode (as it uses more energy).

Output: NOT POSSIBLE

Companies
Topics
Greedy
Scheduling
Simulation
Array
Interval Problems
array manipulation
Optimization
Greedy Algorithms

*************************************************************************************************************************************************************************************************************************************************************************************/

#CODE 
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    for (int room = 0; room < N; ++room) {
        int K, E;
        cin >> K >> E;

        vector<int> schedule(T, 0); // default all hours to Off
        set<int> required_hours;

        // Collect all required hours
        for (int i = 0; i < K; ++i) {
            int L, R;
            cin >> L >> R;
            for (int h = L - 1; h <= R - 1; ++h) {
                required_hours.insert(h);
            }
        }

        int required_count = required_hours.size();

        // Check if Eco mode for all required hours exceeds energy limit
        if (required_count > E) {
            cout << "NOT POSSIBLE" << endl;
            continue;
        }

        // Assign Eco mode to required hours
        for (int h : required_hours) {
            schedule[h] = 1;
        }

        // Output the schedule
        for (int i = 0; i < T; ++i) {
            cout << schedule[i] << " ";
        }
        cout << endl;
    }

    return 0;
}



