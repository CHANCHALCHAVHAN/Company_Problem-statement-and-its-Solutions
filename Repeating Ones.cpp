/*
Problem Statement
Alice has been provided a group of characters. The characters only have 2 types of characters: 0 and 1.

Print the maximum sub-group of characters which are composed of only 1.

Return the ans by 10^9 modulo 7.

Input Format
The first and only line contains a binary string str.

Output Format
Print a single integer RepeatOnes, the number of substrings with only 1s.

Constraints
1 <= str.length() <= 5*105.

str = {1, 0}.

Sample Testcase 0
Testcase Input
0110111
Testcase Output
9
Explanation
There are 9 substrings in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.
Sample Testcase 1
Testcase Input
101
Testcase Output
2
Explanation
Substring "1" is shown 2 times in s.
Companies
Topics
Strings
Hash Table
Sliding Window
Math

*/

#include <iostream>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int countRepeatOnes(const string& str) {
    long long total = 0;
    int count = 0;

    for (char ch : str) {
        if (ch == '1') {
            count++;
        } else {
            total = (total + 1LL * count * (count + 1) / 2) % MOD;
            count = 0;
        }
    }

    // Add the last block if it ends with '1'
    total = (total + 1LL * count * (count + 1) / 2) % MOD;

    return static_cast<int>(total);
}

int main() {
    string str;
    cin >> str;
    cout << countRepeatOnes(str) << endl;
    return 0;
}
