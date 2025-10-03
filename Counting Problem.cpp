/*************************************************************************************************************************************************************************************************************************************************************************************
Problem Statement
Bob loves to play with numbers. He has N numbers, and he has to count the unique numbers according to the given constraints:

A number is considered unique if it is the maximum number present in the collection and has no repetition (i.e., it appears exactly once).
If the maximum number is found to be unique, then Bob counts it as a unique number and removes it from the collection, and inserts half of the number, i.e., number/2 (if number/2 becomes 0, don’t insert it in the collection) in the collection

Else if the maximum number is not found to be unique, then he removes all occurrence of that number from the set.

Bob counts the unique numbers until the collection becomes empty. Can you return the number of unique numbers present in Bob's collection? 

Note: The count of unique numbers can exceed the size of the array as you are inserting number/2 in some cases.

Input Format
The first line of input contains an integer N, representing the size of the array.

The second line of input contains N space-separated integers representing the elements of the array.

Output Format
Display a single integer representing count of unique numbers according to the given constraints.

Constraints
1 <= N <= 10^6.

0<= A[i] <= 10^6.

Sample Testcase 0
Testcase Input
5
1 2 3 3 4
Testcase Output
2
Explanation
Array is [1 2 3 3 4], The maximum number in the collection is 4, which is present in the array only once, so it is unique, remove 4 from the array and insert 4/2, i.e., 2 in the array. 
Now the array becomes [1 2 3 3 2], The maximum number in the collection in the array is now 3, but it is present twice, so it will not be unique, remove both the 3 from the array. 
Now the array becomes [1 2 2], The maximum number in the collection in the array is now 2, but it is present twice, so it will not be unique, remove both the 2 from the array. 
Now the array becomes [1], The maximum number in the collection is 1, which is present in the array only once, so it is unique, remove 1 from the array but do not insert 1/2, i.e., 0(floor value) in the array. 
So, several unique numbers in the collection is 2.

Sample Testcase 1
Testcase Input
1
1
Testcase Output
1
Explanation
The maximum number in the collection is 1, which is present in the array only once, so it is unique, remove 1 from the array but do not insert 1/2, i.e., 0 in the array.
So, a number of unique numbers in the collection is 1.
Companies
Flipkart
Amazon
Topics
Hash Map
Hashing
Counting
Priority Queue

*************************************************************************************************************************************************************************************************************************************************************************************/

#CODE 
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int countUniqueNumbers(vector<int>& nums) {
    unordered_map<int, int> freq;
    priority_queue<int> maxHeap;

    // Initialize frequency map and max heap
    for (int num : nums) {
        freq[num]++;
        maxHeap.push(num);
    }

    int uniqueCount = 0;

    while (!maxHeap.empty()) {
        int currentMax = maxHeap.top();
        maxHeap.pop();

        // If this number has already been removed, skip it
        if (freq[currentMax] == 0) continue;

        if (freq[currentMax] == 1) {
            // Unique max number
            uniqueCount++;
            freq[currentMax] = 0;

            int half = currentMax / 2;
            if (half > 0) {
                freq[half]++;
                maxHeap.push(half);
            }
        } else {
            // Not unique, remove all occurrences
            freq[currentMax] = 0;
        }
    }

    return uniqueCount;
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    cout << countUniqueNumbers(nums) << endl;
    return 0;
}
