/*
PROBLEM STATEMENT
David finds some strings containing only ‘)’ and ‘(‘ parentheses. He is keen to find the length of largest substring that formed the valid bracket sequence. But he does not know how to do it, so help him to find the length of largest valid bracket substring in the given string.

Input Format
The first line contains an integer n – the size of the string.
The second line contains the ‘n’ character of the string.
Output Format
Print a single integer - the length of the largest valid substring
Constraints
0 <= n <= 10000.
String contains only ‘(‘ and ‘)’.
Sample Testcase 0
Testcase Input
3
(()
Testcase Output
2
Explanation
2 is the largest valid substring the given string.
Sample Testcase 1
Testcase Input
6
)()())
Testcase Output
4
Explanation
()() is the largest valid substring which has of length 4.
Companies
TCS
Infosys
Topics
Stack
Stack
*/

//CODE::=>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(const string& s) {
    stack<int> st;
    st.push(-1);  // Base for length calculation
    int maxLen = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (!st.empty()) {
                maxLen = max(maxLen, i - st.top());
            } else {
                st.push(i);  // Reset base
            }
        }
    }

    return maxLen;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << longestValidParentheses(s) << endl;
    return 0;
}
