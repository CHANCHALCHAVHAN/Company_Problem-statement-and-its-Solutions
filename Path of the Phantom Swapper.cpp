/*
Problem Statement
You’re building an AI for a stealth drone that must navigate a linear route of encrypted beacons, each marked with a distinct energy signature (an integer). The drone can only make one "phantom swap" during its path: it can swap any two elements in the array once, to try to create a special property.

The goal of the drone is to minimize the number of "energy peaks" in the beacon path.

An energy peak is defined as an index i such that arr[i] > arr[i - 1] and arr[i] > arr[i + 1].

The AI is allowed to perform at most one swap of any two elements (possibly no swap at all). It must choose the swap that leads to the minimum number of energy peaks after the operation.

Input Format
The first line contains an integer N, representing the number of energy beacons.

The second line contains an array arr of N integers, representing the energy levels of the beacons.

Output Format
Print a single integer representing the minimum number of energy peaks that can be achieved after at most one swap.

Constraints
3 ≤ N ≤ 5*10^3

-10^9 ≤ arr[i] ≤ 10^9

All elements may be distinct or repeated.

At most one swap of any two indices allowed (including no swap).

Sample Testcase 0
Testcase Input
6
3 3 4 2 8 6
Testcase Output
1
Explanation
Initial array: [3, 3, 4, 2, 8, 6]
Peak at index 2: 4 > 3 and 4 > 2 
Peak at index 4: 8 > 2 and 8 > 6 


No other peaks.
Even after swapping every possible elemets at most, there will still a peak left.

Minimum achievable peaks = 1

Sample Testcase 1
Testcase Input
7
1 5 2 6 3 4 7
Testcase Output
0
Explanation
Initial array: [1, 5, 2, 6, 3, 4, 7]
Peaks:
Index 1: 5 > 1 and 5 > 2
Index 3: 6 > 2 and 6 > 3


Try swapping index 0 (1) with index 3 (6) → [6, 5, 2, 1, 3, 4, 7]
New array → No Peak element


Minimum achievable peaks = 0

Companies
Juspay
Wipro
Paypal
Topics
Greedy
Simulation
Optimization
Arrays
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int separatePeaks(vector<int>& arr) {
        int n = arr.size();

        auto isPeak = [&](int i) {
            return i > 0 && i < n - 1 &&
                   arr[i] > arr[i - 1] &&
                   arr[i] > arr[i + 1];
        };

        // Count initial peaks
        int basePeaks = 0;
        for (int i = 1; i < n - 1; i++)
            if (isPeak(i)) basePeaks++;

        int ans = basePeaks;

        // Try all swaps
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                set<int> affected;

                for (int d = -1; d <= 1; d++) {
                    if (i + d > 0 && i + d < n - 1)
                        affected.insert(i + d);
                    if (j + d > 0 && j + d < n - 1)
                        affected.insert(j + d);
                }

                int removed = 0;
                for (int idx : affected)
                    if (isPeak(idx)) removed++;

                swap(arr[i], arr[j]);

                int added = 0;
                for (int idx : affected)
                    if (isPeak(idx)) added++;

                ans = min(ans, basePeaks - removed + added);

                swap(arr[i], arr[j]); // restore
            }
        }

        return ans;
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Solution sol;
    cout << sol.separatePeaks(arr) << endl;

    return 0;
}
