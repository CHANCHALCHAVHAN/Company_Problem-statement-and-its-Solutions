/*
Problem Statement
Sid is analyzing the selling prices in different cities and wants to identify a longest contiguous subsequence of consecutive cities where prices are strictly increasing. However, he has a unique way of calculating profits:

He is only interested in prime numbers that are also "double prime numbers" (A double prime number is a prime number p such that p+2 is also prime).

Find the longest strictly increasing subsequence of prices.

Calculate the maximum sum of double prime numbers in that subsequence.

If multiple subsequences have the same length, choose the one with the highest sum of double primes.

If no double prime numbers are found, return 0 for the prime sum.

Input Format
The first line contains a single integer n, representing the number of cities (length of the array).

The second line contains n space-separated integers, representing the selling prices in different cities.

Output Format
Print two space-separated integers:

The length of the longest strictly increasing subsequence.

The sum of double prime numbers in that subsequence.

Constraints
1 ≤ arr.length ≤ 10^5

1 ≤ arr[i] ≤ 10^5

Expected Time Complexity: O(n sqrt(n))

Expected Space Complexity: O(n)

Sample Testcase 0
Testcase Input
5
3 5 7 11 3
Testcase Output
4 19
Explanation
We have 5 cities with prices: 3, 5, 7, 11, 3
The longest strictly increasing subsequence is [3, 5, 7, 11] with length 4
Among these numbers, the double primes are:
- 3 (because 3 and 5 are both prime)
- 5 (because 5 and 7 are both prime)
- 11 (because 11 and 13 are both prime)
Sum of double primes: 3 + 5 + 11 = 19
Therefore, output is "4 19"

Sample Testcase 1
Testcase Input
5
4 6 8 10 12
Testcase Output
5 0
Explanation
We have 5 cities with prices: 4, 6, 8, 10, 12
The entire sequence [4, 6, 8, 10, 12] is strictly increasing with length 5
None of these numbers are double primes:
- 4 is not prime
- 6 is not prime
- 8 is not prime
- 10 is not prime
- 12 is not prime
Sum of double primes: 0 (since there are no double primes)
Therefore, output is "5 0"

Companies
Qualcomm
Amazon
Juspay
Topics
Data Structures
Mathematics, Algorithms
Array
Arrays
*/
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool isDoublePrime(int x) {
    return isPrime(x) && isPrime(x + 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> input;
    int x;
    while (cin >> x) {
        input.push_back(x);
    }

    int n = input[0];
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back(input[i]);
    }

    int bestLen = 1, currLen = 1;
    long long bestSum = 0;
    long long currSum = isDoublePrime(arr[0]) ? arr[0] : 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            currLen++;
            if (isDoublePrime(arr[i])) currSum += arr[i];
        } else {
            if (currLen > bestLen || 
               (currLen == bestLen && currSum > bestSum)) {
                bestLen = currLen;
                bestSum = currSum;
            }
            currLen = 1;
            currSum = isDoublePrime(arr[i]) ? arr[i] : 0;
        }
    }

    // Final check
    if (currLen > bestLen || 
       (currLen == bestLen && currSum > bestSum)) {
        bestLen = currLen;
        bestSum = currSum;
    }

    cout << bestLen << " " << bestSum;
    return 0;
}
