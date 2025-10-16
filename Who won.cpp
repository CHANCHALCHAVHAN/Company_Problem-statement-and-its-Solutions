/*
Problem Statement
Utkarsh and Ashish are engaged in a strategic game. The game is played in turns, with Ashish always making the first move.

The game is played on a 2D plane, with a token initially placed at the origin point (0,0).
In each turn, a player must move the token by increasing either the x-coordinate or the y-coordinate by exactly 'k' units.
However, the player must ensure that the token remains within a Euclidean distance 'd' from the origin point (0,0). This means that if the token's coordinates after a move are (p,q), then the condition p^2 + q^2 ≤ d^2 must be satisfied.
The game ends when a player cannot make a valid move. It is guaranteed that the game will end after a finite number of moves. Assuming both players play optimally, your task is to determine the winner of the game.

Input Format
The input consists of a single line for each test case, containing two space-separated integers 'd' and 'k' denoting the Euclidean distance from the origin point and the token by increasing either the x-coordinate or the y-coordinate by exactly 'k' units respectively.

Output Format
Print "Ashish" if Ashish wins the game, and "Utkarsh" if Utkarsh wins. The output should not contain any quotes.

Constraints
1 ≤ d ≤ 10^9
1 ≤ k ≤ d
Sample Testcase 0
Testcase Input
2 1
Testcase Output
Utkarsh
Explanation
Ashish moves the token to (1,0). Utkarsh then moves it to (1,1) or (2,0). Ashish cannot move without exceeding (d = 2). Thus, Ashish loses, and Utkarsh wins. Therefore, the output is "Utkarsh".

Sample Testcase 1
Testcase Input
5 2
Testcase Output
Ashish
Explanation
Ashish wins because he starts first and can always place the token in positions where Utkarsh eventually cannot make a valid move within the Euclidean distance constraint d = 5. Ashish's optimal moves force Utkarsh into a losing position.

Companies
Flipkart
Microsoft
Topics
Math
Game Theory
Matrix


*/

#CODE

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long d, k;
    cin >> d >> k;

    // Find the maximum number of diagonal moves (x = y = steps * k)
    long long steps = 0;
    while ((steps + 1) * k * (steps + 1) * k * 2 <= d * d) {
        steps++;
    }

    // Check if one more move in either direction is still valid
    bool canMoveFurther = false;
    long long x1 = (steps + 1) * k;
    long long y1 = steps * k;
    long long x2 = steps * k;
    long long y2 = (steps + 1) * k;

    if (x1 * x1 + y1 * y1 <= d * d || x2 * x2 + y2 * y2 <= d * d) {
        canMoveFurther = true;
    }

    // If further move is possible, Ashish wins; otherwise Utkarsh wins
    if (canMoveFurther) {
        cout << "Ashish" << endl;
    } else {
        cout << "Utkarsh" << endl;
    }

    return 0;
}
