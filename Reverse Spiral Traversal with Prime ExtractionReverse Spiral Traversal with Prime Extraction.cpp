/*
Problem Statement
You are given a rectangular matrix mat[][] of size M x N. Your task is to return three outputs while traversing the matrix in spiral order, starting from the bottom-right corner and moving towards the top-left corner.

Requirements:

First Output: The elements of the matrix in spiral order starting from bottom-right (M-1, N-1).
Second Output: An array containing only the prime numbers in the order they appear in the traversal. return 0 if no prime exist.
Third Output: The sum of all prime numbers found in the traversal.
Input Format
The first line contains two integers, M and N, representing the dimensions of the matrix.

The next M lines contain N space-separated integers, representing the matrix elements.

Output Format
Print:

A single line containing the elements in reverse spiral order.
A single line containing only the prime numbers from that sequence. return 0 in case of no primes.
A single integer representing the sum of the prime numbers.
Constraints
1 <= M, N <= 1000

1 <= mat[i][j] <= 10^6

Sample Testcase 0
Testcase Input
4 4
1  2  3  4
5  6  7  8
9 10 11 12
13 14 15 16
Testcase Output
16 15 14 13 9 5 1 2 3 4 8 12 11 10 6 7
13 5 2 3 11 7
41
Explanation
Spiral order (reverse start): [16, 15, 14, 13, 9, 5, 1, 2, 3, 4, 8, 12, 11, 10, 6, 7]


Prime numbers extracted: [13, 5, 2, 3, 11, 7]


Sum of primes: 13 + 5 + 2 + 3 + 11 + 7 = 41

Sample Testcase 1
Testcase Input
3 5
29  30  31  32  33
23  24  25  26  27
19  17  13  11   7
Testcase Output
7 11 13 17 19 23 29 30 31 32 33 27 26 25 24
7 11 13 17 19 23 29 31
150
Explanation
Step-by-Step Spiral Order (Reverse)


Start from bottom-right (7) → move left: [7, 11, 13, 17, 19]
Move up (column 0): [7, 11, 13, 17, 19, 23]
Move right (row 0): [7, 11, 13, 17, 19, 23, 29, 30, 31, 32, 33]
Move down (column 4): [7, 11, 13, 17, 19, 23, 29, 30, 31, 32, 33, 27]
Move left (row 1): [7, 11, 13, 17, 19, 23, 29, 30, 31, 32, 33, 27, 26, 25, 24]

Prime Numbers in this Order
Extracting only prime numbers from the sequence: 7 11 13 17 19 23 29 31


 


 


Sum of Prime Numbers: 7 + 11 + 13 + 17 + 19 + 23 + 29 + 31 = 150


 

Companies
Amazon
Mastercard
Topics
Recursion
Mathematical Calculations
Matrix

*/
#include <bits/stdc++.h>
using namespace std;

bool isPrimeNum(int x, vector<bool> &prime){
    if(x <= 1) return false;
    return prime[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> mat(M, vector<int>(N));
    int maxVal = 0;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
            maxVal = max(maxVal, mat[i][j]);
        }
    }

    // Sieve for primes up to max value
    vector<bool> prime(maxVal + 1, true);
    if(maxVal >= 0){
        prime[0] = false;
        if(maxVal >= 1) prime[1] = false;
    }
    for(int i = 2; i * i <= maxVal; i++){
        if(prime[i]){
            for(int j = i * i; j <= maxVal; j += i)
                prime[j] = false;
        }
    }

    vector<int> spiral;
    int top = 0, bottom = M - 1, left = 0, right = N - 1;

    while(top <= bottom && left <= right){

        // 1️⃣ Move LEFT along bottom row
        for(int j = right; j >= left; j--)
            spiral.push_back(mat[bottom][j]);
        bottom--;

        if(top > bottom) break;

        // 2️⃣ Move UP along left column
        for(int i = bottom; i >= top; i--)
            spiral.push_back(mat[i][left]);
        left++;

        if(left > right) break;

        // 3️⃣ Move RIGHT along top row
        for(int j = left; j <= right; j++)
            spiral.push_back(mat[top][j]);
        top++;

        if(top > bottom) break;

        // 4️⃣ Move DOWN along right column
        for(int i = top; i <= bottom; i++)
            spiral.push_back(mat[i][right]);
        right--;
    }

    // Output 1: Spiral Order
    for(int x : spiral) cout << x << " ";
    cout << "\n";

    // Output 2 & 3: Prime extraction and sum
    vector<int> primes;
    long long sum = 0;

    for(int x : spiral){
        if(isPrimeNum(x, prime)){
            primes.push_back(x);
            sum += x;
        }
    }

    if(primes.empty()){
        cout << 0 << "\n";
        cout << 0 << "\n";
    } else {
        for(int p : primes) cout << p << " ";
        cout << "\n";
        cout << sum << "\n";
    }

    return 0;
}
