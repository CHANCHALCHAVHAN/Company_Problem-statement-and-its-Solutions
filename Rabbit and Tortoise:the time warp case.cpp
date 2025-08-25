/*
PROBLEM STATEMENT
Problem Statement
In a mythical race between a Rabbit and a Tortoise, they run along a straight track with N checkpoints labeled 0 to N-1. Each checkpoint may have a special time warp effect that alters the Rabbit’s movement.

Tortoise's Movement

Moves exactly 1 checkpoint per second.

Moving from checkpoint i to i+1 takes 1 second.

Total race time for the Tortoise is always N - 1 seconds.

Rabbit's Movement

Normally moves 2 checkpoints per second.

If fewer than 2 checkpoints remain to the finish, the Rabbit still attempts to move 2 checkpoints in that step (possibly overshooting the finish).

The Rabbit’s movement can be altered by the tw[] array (size N), where tw[i] describes the tile effect at checkpoint i.

Tile Effects

Delay Tile (tw[i] > 0)

On the first visit, the Rabbit must wait tw[i] seconds before moving again.

This wait happens before the next move.

On later visits, this checkpoint is treated as a normal tile.

Trap Tile (tw[i] = -1)

On the first visit, the Rabbit is sent back 1 checkpoint immediately, taking 1 extra second.

The forward movement to the trap still consumes normal travel time.

If the trap is at checkpoint 0, the Rabbit stays there instead of moving back.

On later visits, the trap is ignored.

Normal Tile (tw[i] = 0)

No extra effects — the Rabbit moves at normal speed.

Race Rules

Both start at checkpoint 0.

The Rabbit does not apply the effect of checkpoint 0 before its first move.

The race ends as soon as a runner reaches or passes checkpoint N-1.

If both reach in the same time, it’s a tie.

Input Format
First line: A single integer N 

Second line: N space-separated integers representing the time-warp tiles:

Output Format
Print "Rabbit" if the Rabbit finishes first, "Tortoise" if the Tortoise finishes first,
or "Tie" if both finish in the same time.

Constraints
2 ≤ N ≤ 10^5

-1 ≤ tw[i] ≤ 10^4

Sample Testcase 0
Testcase Input
9  
0 -1 0 -1 3 0 0 0 0
Testcase Output
Rabbit
Explanation
Rabbit:
Start at 0 → move to 2 (1s)
At 2: normal → move to 4 (+1s) → total = 2s
At 4: delay (3s) → wait → total = 5s
Move from 4 to 6 (+1s) → total = 6s
Move from 6 to 8 (+1s) → total = 7s (finish)


Tortoise:
Moves 0 → 8 in 8s


Winner: Rabbit.

Sample Testcase 1
Testcase Input
7  
0 0 -1 2 0 0 0
Testcase Output
Tortoise
Explanation
Rabbit:
Start at 0 → move to 2 (1s)
At 2: trap (-1) → sent back to 1 (+1s) → total = 2s
At 1: normal → move to 3 (+1s) → total = 3s
At 3: delay (2s) → wait → total = 5s
Move from 3 to 5 (+1s) → total = 6s
Move from 5 to 7 (overshoots finish, +1s) → total = 7s (finish)


Tortoise:
Moves 0 → 6 in 6s


Winner: Tortoise.

Companies
Topics
Simulation
Greedy
Array
Game Theory
Conditionals
Data Structure
GameTheory
*/
#include <iostream>
#include <vector>
using namespace std;

string raceWinner(int N, const vector<int>& tw) {
    int tortoise_time = N - 1;
    int rabbit_time = 0;
    int pos = 0;
    vector<bool> visited(N, false);

    while (pos < N - 1) {
        int next_pos = pos + 2;
        rabbit_time += 1; // time to move

        if (next_pos >= N) next_pos = N - 1;

        // Apply tile effect at next_pos if not visited
        if (!visited[next_pos]) {
            visited[next_pos] = true;

            if (tw[next_pos] == -1) {
                rabbit_time += 1; // trap penalty
                next_pos = max(0, next_pos - 1); // move back
            } else if (tw[next_pos] > 0) {
                rabbit_time += tw[next_pos]; // delay penalty
            }
        }

        pos = next_pos;
    }

    if (rabbit_time < tortoise_time) return "Rabbit";
    else if (rabbit_time > tortoise_time) return "Tortoise";
    else return "Tie";
}

int main() {
    int N;
    cin >> N;
    vector<int> tw(N);
    for (int i = 0; i < N; ++i) {
        cin >> tw[i];
    }
    cout << raceWinner(N, tw) << endl;
    return 0;
}
