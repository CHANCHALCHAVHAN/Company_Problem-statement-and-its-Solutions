/*
Problem Statement
Ravi discovered a special type of number called Filo Numbers, which are any numbers that can be expressed as a sum of consecutive natural numbers.
He found that every positive integer can be represented as a Filo Number. However, he realized that some integers can be expressed as a Filo Number in multiple ways.
Now, he needs help calculating how many different ways a given positive integer N can be expressed as a Filo Number.

Input Format
The first and only line of input contains an integer N.

Output Format
Print an integer which represent the number of ways N can be expressed as a Filo Number.

Constraints
1 <= N <= 10^6

Sample Testcase 0
Testcase Input
9
Testcase Output
3
Explanation
There are three ways in which nine can be expressed as a Filo Number -> 
(9), (2 + 3 + 4), (4+5)
Sample Testcase 1
Testcase Input
15
Testcase Output
4
Explanation
There are four ways in which 15 can be expressed as a Filo Number ->
(15), (8+7), (4+5+6), (1+2+3+4+5)
Companies
Zoho
Wipro
Topics
Math
Number Theory
Array


*/
#include <iostream>
using namespace std;

int countFiloWays(int N) {
    int count = 0;

    // Try all possible lengths k of the sequence
    for (int k = 1; k * (k + 1) / 2 <= N; ++k) {
        int numerator = 2 * N - k * (k - 1);
        if (numerator % (2 * k) == 0) {
            int x = numerator / (2 * k);
            if (x > 0) count++;
        }
    }

    return count;
}

int main() {
    int N;
    cin >> N;
    cout << countFiloWays(N) << endl;
    return 0;
}
