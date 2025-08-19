/***************************************************************************************************************************************************************************************************************** 
PROBLEM STATEMENT
Problem Statement
Archan is a professor at the Academy Of Technology. One day he calls his student Niladri to play an interesting game. He asked Niladri to imagine an empty bucket. He then does K queries. In each query he asks Niladri to do either of the following operations:

Add a number V to the bucket.
Get the median of all numbers added to the bucket.
Niladri needs to answer Archan only in the type 2 query. Can you help Niladri to do so?

Note: Answer within one decimal place of the actual answer will be accepted.

Input Format
First-line contains K- the number of queries that Archan will ask. K subsequent lines follow.
Each line contains the type of query whether it is “add” or “get” followed by a space and then the value v if it's an “add” query.
First query will always be “add”. There will be at least one “get” query.

Output Format
The output contains several lines(one or more) each denoting the answer of each “get” query.
The answer should always be formatted to one decimal place. 

Constraints
2<=K<=106
 1<=V<=106
Sample Testcase 0
Testcase Input
9
add 1
add 8
add 4
add 15
add 12
get
add 46
add 25
get
Testcase Output
8.0
12.0
Explanation
Before the first “get” the elements added were 1,4,8,12 and 15 whose median is 8.0 and before second “get” the elements in array are 1,4,8,12,15,46 and 25 whose median is 12.0
Sample Testcase 1
Testcase Input
6
add 5
add 10
add 3
get
add 7
get
Testcase Output
5.0
6.0
Sample Testcase 2
Testcase Input
5
add 1
add 2
add 3
get
get
Testcase Output
2.0
2.0
Sample Testcase 3
Testcase Input
7
add 1
add 4
add 2
add 9
get
add 7
get
Testcase Output
3.0
4.0
Explanation
Before the first “get” the elements added were 1,4,2 and 9 whose median is (2+4)/2=3.0 and before second “get” the elements in array are 1,4,2,7 and 9 whose median is 4.0
Companies
Indeed
Accenture
OYO Rooms
Topics
Heap
PriorityQueue
Sorting
****************************************************************************************************************************************************************************************************************/


//CODE::=>
#include <iostream>
#include <queue>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    priority_queue<int> left; // Max-heap
    priority_queue<int, vector<int>, greater<int>> right; // Min-heap

    for (int i = 0; i < K; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int val;
            cin >> val;

            if (left.empty() || val <= left.top()) {
                left.push(val);
            } else {
                right.push(val);
            }

            // Balance the heaps
            if (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            } else if (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }

        } else if (cmd == "get") {
            double median;
            if (left.size() == right.size()) {
                median = (left.top() + right.top()) / 2.0;
            } else {
                median = left.top();
            }
            cout << fixed << setprecision(1) << median << '\n';
        }
    }

    return 0;
}
