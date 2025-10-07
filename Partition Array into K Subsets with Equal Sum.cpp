/*************************************************************************************************************************************************************************************************************************************************************************************
Problem Statement
You are given an integer array arr[] of length N and an integer K. Your task is to determine if the array can be partitioned into exactly k non-empty subsets, such that:

All subsets have equal sum.

No element is repeated in any subset.

Each subset has a length of at least 1.

You can use each element only once in any of the subsets.

Additional Requirement:

The partitioning should be done using a recursive backtracking approach.

Input Format
A list of integers arr[] where each element arr[i] represents the value of an integer in the array.

An integer K, the number of subsets to partition the array into.

Output Format
Display True if it is possible to partition the array into k non-empty subsets with equal sum, otherwise return False.

Constraints
1 ≤ K ≤ arr.size() ≤ 10^2

1 ≤ arr[i] ≤ 10^2

Sample Testcase 0
Testcase Input
2 1 4 5 6
3
Testcase Output
true
Explanation
The array [2, 1, 4, 5, 6] can be partitioned into 3 subsets with equal sum:




Subset 1: [2, 4]




Subset 2: [1, 5]




Subset 3: [6]




Each subset has a sum of 6, so the output is true.

Sample Testcase 1
Testcase Input
2 1 5 5 6
3
Testcase Output
false
Explanation
The array [2, 1, 5, 5, 6] cannot be partitioned into 3 subsets with equal sum because the sum of the array is 19, which is not divisible by 3. Hence, it's not possible to divide it into 3 subsets with equal sum.

Companies
Topics
Backtracking
Data structure and algorithm
Dynamic Programming

*************************************************************************************************************************************************************************************************************************************************************************************/

#CODE 
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool canPartition(int index, vector<int>& arr, vector<int>& subsetSum, int target) {
    if (index == arr.size()) {
        // Check if all subsets have reached the target sum
        for (int i = 0; i < subsetSum.size(); ++i) {
            if (subsetSum[i] != target) return false;
        }
        return true;
    }

    int current = arr[index];
    for (int i = 0; i < subsetSum.size(); ++i) {
        if (subsetSum[i] + current <= target) {
            subsetSum[i] += current;
            if (canPartition(index + 1, arr, subsetSum, target)) return true;
            subsetSum[i] -= current;
        }

        // Optimization: if this subset is still empty, no need to try other empty ones
        if (subsetSum[i] == 0) break;
    }

    return false;
}

bool isKPartitionPossible(vector<int>& arr, int k) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if (totalSum % k != 0 || arr.size() < k) return false;

    int target = totalSum / k;
    sort(arr.rbegin(), arr.rend()); // Start with largest elements for pruning
    vector<int> subsetSum(k, 0);

    return canPartition(0, arr, subsetSum, target);
}

int main() {
    vector<int> arr = {2, 1, 4, 5, 6}; // Sample input
    int k = 3;

    cout << boolalpha << isKPartitionPossible(arr, k) << endl;
    return 0;
}
