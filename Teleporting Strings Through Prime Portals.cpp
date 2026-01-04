/*
Problem Statement
You're given a string S of length N, and an array P[1...K] of K positive integers, each representing prime portal indices (1-based).

Each prime portal allows teleportation of a character to any other portal index, but with constraints:

You can only teleport characters that are at a prime index in the string (1-based).

You may perform at most M teleportations total (across any characters).

Your goal is to determine:

The lexicographically largest string that can be obtained from S after at most M valid teleportations using portals.

If it's not possible to make any teleportation, return the original string.

Input Format
First line contains three integers N, K, and M

Second line contains a string S of length N

Third line contains K space-separated integers P[1] P[2] ... P[K]

Output Format
Print the lexicographically largest string obtainable after applying at most M valid teleportations using the portal rules.

Constraints
1 ≤ N ≤ 10^5

1 ≤ K ≤ 10^5

1 ≤ P[i] ≤ N

0 ≤ M ≤ 10^5

S consists of only lowercase English letters.

Sample Testcase 0
Testcase Input
6 4 3
gfedcb
2 3 5 6
Testcase Output
gfedcb
Explanation
String: "gfedcb"


Portal indices: [2, 3, 5, 6] → characters: f, e, c, b


Prime indices among them: 2, 3, 5 → only positions 2 (f), 3 (e), 5 (c) are valid


3 teleportations allowed


Now, check if we can get any improvement:


Try f (2) to e (3) → no gain


Try f (2) to c (5) → c < f → swap: gcedfb


Try e (3) to f (new 2) → now at position 2 is c, not worth it


Nothing more improves lexicographically


But if we actually simulate it carefully, we find:


The largest possible string still ends up as "gfedcb" — any teleportation increases lexicographical order.

Sample Testcase 1
Testcase Input
5 3 2
dcbaz
2 3 5
Testcase Output
dzcab
Explanation
String: "dcbaz"


Portal indices: [2, 3, 5] → 1-based → positions 2 (c), 3 (b), 5 (z)


Primes among them: 2, 3, 5 → All are prime


You can do up to 2 teleportations


Let's analyze:


From position 2 (c), teleport to 5 (z) → "dcbaz" → "dzbac"


Now, from position 3 (b), teleport to 5 (c) → "dzbac" → "dzcab"

Companies
Juspay
Mastercard
Infosys
Topics
Greedy
Mathematics, Greedy
Simulation
Sorting
String
String Manipulation
greedy

*/



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, M;
    cin >> N >> K >> M;

    string S;
    cin >> S;

    vector<int> P(K);
    for (int i = 0; i < K; i++) {
        cin >> P[i];
        P[i]--; // convert to 0-based
    }

    // Step 1: Sieve for primes up to N
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }

    // Step 2: collect valid indices
    set<int> valid;
    for (int idx : P) {
        if (isPrime[idx + 1]) {
            valid.insert(idx);
        }
    }

    // Step 3: Greedy swaps
    for (int i = 0; i < N && M > 0; i++) {
        if (!valid.count(i)) continue;

        char bestChar = S[i];
        int bestPos = -1;

        for (int j : valid) {
            if (j > i && S[j] > bestChar) {
                bestChar = S[j];
                bestPos = j;
            }
        }

        if (bestPos != -1) {
            swap(S[i], S[bestPos]);
            M--;
        }
    }

    cout << S << "\n";
    return 0;
}





























