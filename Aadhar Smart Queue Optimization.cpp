/*
Problem Statement
A government office processes Aadhar card-related services like new applications, updates, and reprints. Each person in the queue has a different urgency level and service type. The office wants to prioritize people based on urgency level and arrival time to reduce wait time for critical cases.

Each person in the queue is represented as a structure containing:

arrivalTime (in minutes from 0),

urgencyLevel (1 to 5; where 5 is most urgent),

serviceType (1 = New Registration, 2 = Update, 3 = Reprint)

You are given data for N people. The office can serve only K people in a day.

Your task is to return the order of processing (by person ID) such that:

Persons with higher urgencyLevel are served first.

If urgencyLevel is the same, serve the person who arrived earlier.

If still same, give priority to New Registration > Update > Reprint.

Input Format
The first line contains two integers N and K.

The next N lines contain: personID arrivalTime urgencyLevel serviceType

Output Format
Print the K personIDs in the order they will be served.

Constraints
1 ≤ N ≤ 20000  
1 ≤ K ≤ 1000  
0 ≤ arrivalTime ≤ 10^4  
1 ≤ urgencyLevel ≤ 5  
1 ≤ serviceType ≤ 3  

Sample Testcase 0
Testcase Input
4 2  
201 10 3 2  
202 10 3 1  
203 10 3 3  
204 10 3 1
Testcase Output
202  
204
Explanation
All have same urgencyLevel (3) and same arrivalTime (10).


Use serviceType as tie-breaker: 1 (New) > 2 (Update) > 3 (Reprint)


202 and 204 have serviceType = 1, so both chosen first.


Their order is based on personID order from input (202 before 204).

Sample Testcase 1
Testcase Input
5 3  
101 30 4 2  
102 25 4 1  
103 45 5 3  
104 20 4 1  
105 60 3 1
Testcase Output
103  
104  
102
Explanation
Person 103 has the highest urgencyLevel = 5, so served first.


Next, among those with urgency 4:


104 (arrival 20), 102 (25), and 101 (30)


104 and 102 arrived earlier than 101.


104 and 102 have the same serviceType (1), but 104 arrived earlier.


So the order is: 103, 104, 102

Companies
Topics
Greedy
Sorting
PriorityQueue
Custom Comparator
Queue
Simulation
Algorithms, Implementation
Greedy Algorithms
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure for a Person
struct Person {
    int personID;
    int arrivalTime;
    int urgencyLevel;
    int serviceType;
    int index; // to preserve input order

    Person(int id, int arrival, int urgency, int service, int idx)
        : personID(id), arrivalTime(arrival), urgencyLevel(urgency),
          serviceType(service), index(idx) {}
};

// Comparator function
bool cmp(const Person &a, const Person &b) {
    // 1. Higher urgency first
    if (a.urgencyLevel != b.urgencyLevel)
        return a.urgencyLevel > b.urgencyLevel;

    // 2. Earlier arrival first
    if (a.arrivalTime != b.arrivalTime)
        return a.arrivalTime < b.arrivalTime;

    // 3. Service priority: 1 > 2 > 3
    if (a.serviceType != b.serviceType)
        return a.serviceType < b.serviceType;

    // 4. Input order
    return a.index < b.index;
}

// User logic
vector<int> user_logic(int N, int K, vector<Person>& people) {
    sort(people.begin(), people.end(), cmp);

    vector<int> result;
    for (int i = 0; i < K && i < people.size(); i++) {
        result.push_back(people[i].personID);
    }
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Person> people;

    for (int i = 0; i < N; ++i) {
        int id, arrival, urgency, service;
        cin >> id >> arrival >> urgency >> service;
        people.emplace_back(id, arrival, urgency, service, i);
    }

    vector<int> result = user_logic(N, K, people);

    for (int personID : result) {
        cout << personID << endl;
    }

    return 0;
}
