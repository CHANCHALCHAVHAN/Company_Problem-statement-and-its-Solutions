/*
Problem Statement
In an ancient encrypted messaging system, each message is represented as a string S consisting of only symbols: #, @, $, %, &, *, and !.

A message is said to be "symbolically stable" if the following conditions are met:

Each distinct symbol in the message occurs an even number of times.

No two adjacent symbols in the message are the same.

The message has at least one of each of the seven allowed symbols.

Your task is to write a function that:

Returns "STABLE" if the message is symbolically stable.

Otherwise, returns "UNSTABLE".

Input Format
A single line containing a string S

Output Format
Print  "STABLE" if the message satisfies all three stability conditions. Otherwise print "UNSTABLE".

Constraints
1 <= S <= 10^5

Sample Testcase 0
Testcase Input
@#@#$$%%!!**&&
Testcase Output
UNSTABLE
Explanation
 All 7 required symbols (@#%$*!&) are present.


 All symbols appear exactly 2 times (even).


Adjacent duplicates found:


$$, %%, !!, **, &&


Fails Rule 2 → Output: UNSTABLE

Sample Testcase 1
Testcase Input
@#%$*!&@#%$*!&
Testcase Output
STABLE
Explanation
All 7 symbols present.


Each symbol appears twice → even count.


No adjacent duplicates: e.g., @#%$*!&@#%$*!& — all alternating.


Passes all 3 rules → Output: STABLE

Companies
Topics
String Manipulation
Frequency Counting
Hashmap
String Validation
Greedy
Set Operations
Strings
*/

//CODE::=>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string checkStability(const string& S) {
    unordered_map<char, int> freq;
    unordered_set<char> requiredSymbols = {'#', '@', '$', '%', '&', '*', '!'};

    // Rule 1 & 3: Count frequencies and check presence of all required symbols
    for (char ch : S) {
        freq[ch]++;
        requiredSymbols.erase(ch); // Remove if found
    }

    if (!requiredSymbols.empty()) {
        return "UNSTABLE"; // Missing one or more required symbols
    }

    for (auto& [symbol, count] : freq) {
        if (count % 2 != 0) {
            return "UNSTABLE"; // Odd frequency found
        }
    }

    // Rule 2: Check for adjacent duplicates
    for (size_t i = 1; i < S.size(); ++i) {
        if (S[i] == S[i - 1]) {
            return "UNSTABLE"; // Adjacent duplicates found
        }
    }

    return "STABLE";
}

int main() {
    string S;
    cin >> S;
    cout << checkStability(S) << endl;
    return 0;
}
