/*
Problem Statement
A Cyber Cafe has N computers. Each customer who logs in is assigned a computer (if one is free). Every customer provides:

An ID

An arrival time

A duration (in minutes) they plan to use the computer

Your task is to manage the Cyber Cafe session allocations and report the number of customers M who were denied access because no computer was free at their arrival time.

You are given a list of customer session requests in chronological order of arrival.

Input Format
The first line contains an integer N

The second line contains an integer M

The next M lines each contain information for one customer, formatted as: ID ARRIVAL_TIME DURATION

Output Format
Print the number of customers who were denied access.

Constraints
1 ≤ N ≤ 50

1 ≤ M ≤ 10^4

1 ≤ duration ≤ 300

0 ≤ arrival ≤ 10^5

All arrival times are in non-decreasing order.

Sample Testcase 0
Testcase Input
3
4
U1 5 20
U2 10 10
U3 15 5
U4 25 15
Testcase Output
0
Explanation
U1, U2, U3 arrive at different times, all get a computer.


At 25, U3 and U2 are done → U4 gets a computer.


No one denied → Output: 0

Sample Testcase 1
Testcase Input
2
5
C1 0 60
C2 10 30
C3 20 30
C4 70 60
C5 80 30
Testcase Output
1
Explanation
C1 arrives at 0 → gets a computer till 60


C2 arrives at 10 → gets another computer till 40


C3 arrives at 20 → both computers are busy → denied


C4 arrives at 70 → both previous sessions ended → gets a computer


C5 arrives at 80 → another computer is free → gets a computer


Only C3 is denied → Output: 1

Companies
Topics
PriorityQueue
min heap
Greedy
Simulation
Sorting
Resource Allocation
Greedy Algorithms
*/
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.PriorityQueue;

class Customer {
    String id;
    int arrival;
    int duration;
    
    Customer(String id, int arrival, int duration) {
        this.id = id;
        this.arrival = arrival;
        this.duration = duration;
    }
}

public class Main {
    public static int countDeniedCustomers(int N, List<Customer> customers) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(); 
        int denied = 0;

        for (Customer c : customers) {

            // Free computers whose sessions ended
            while (!pq.isEmpty() && pq.peek() <= c.arrival) {
                pq.poll();
            }

            // If computer available
            if (pq.size() < N) {
                pq.offer(c.arrival + c.duration); // assign computer
            } else {
                denied++; // no computer free
            }
        }

        return denied;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        List<Customer> customers = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            String id = scanner.next();
            int arrival = scanner.nextInt();
            int duration = scanner.nextInt();
            customers.add(new Customer(id, arrival, duration));
        }

        int deniedCustomers = countDeniedCustomers(N, customers);
        System.out.println(deniedCustomers);
        scanner.close();
    }
}
