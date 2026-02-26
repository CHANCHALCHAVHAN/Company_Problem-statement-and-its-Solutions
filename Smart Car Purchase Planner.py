'''/*
Problem Statement
Ravi wants to buy a new car. The car market in his city offers N different cars. Each car has:

A base cost B[i]

An EMI plan E[i] (monthly installment for T[i] months)

A discount D[i] that applies only if the full payment is made upfront

Ravi has a budget of K and wants to buy only one car. He has the option to:

Pay full upfront: This will cost him B[i] - D[i]

Go for EMI: This will cost him E[i] * T[i] (total EMI amount)

But there's a twist!

Ravi hates long EMI plans. He will only consider EMI plans of at most M months.

Your task is to help Ravi find the maximum value car he can buy within his budget K. The value of a car is simply its base cost B[i].

If Ravi cannot afford any car, return -1.

Input Format
First line contains three integers N, K, and M

Next N lines: Each line contains four integers B[i], E[i], T[i], and D[i]

Output Format
Print the maximum base cost of a car that Ravi can buy (either via EMI or upfront) within his budget K.If no car can be bought, print -1.

Constraints
1 <= N <= 10^4

1 <= K <= 10^9

1 <= M <= 60

1 <= B[i], E[i], T[i], D[i] <= 10^6

Sample Testcase 0
Testcase Input
2 100000 24
90000 4000 24 5000
85000 3000 36 4000
Testcase Output
90000
Explanation
Budget = ₹100,000


Max EMI months = 24


Car 0:


EMI: 4000 × 24 = 96000 Valid


Upfront: 90000 - 5000 = 85000 Valid
→  Ravi can afford both options → base = 90000


Car 1:


EMI duration = 36 > 24  (not allowed)


Upfront: 85000 - 4000 = 81000 Valid
→Only upfront is valid → base = 85000


Maximum base value Ravi can afford = 90000

Sample Testcase 1
Testcase Input
2 50000 12
60000 5000 12 5000
70000 3000 10 10000
Testcase Output
70000
Explanation
Budget: ₹50000


Car 0:


EMI = 5000 × 12 = 60000 Invalid


Upfront = 60000 - 5000 = 55000 Invalid


Car 1:


EMI = 3000 × 10 = 30000 Valid


Upfront = 70000 - 10000 = 60000 Invalid
→ EMI valid, but EMI = 30000 Valid
→ Base = 70000


But wait! Ravi can afford only 50000, and EMI cost is 30000, which is affordable 
→ Correction: Ravi can afford Car 1


Max base value = 70000

Companies
Topics
Greedy
Algorithms, Implementation
Array
conditional logics
Math
Optimization
Greedy Algorithms
*/'''
class Car:
    def __init__(self, base, emi, time, discount):
        self.base = base
        self.emi = emi
        self.time = time
        self.discount = discount

def calculate_max_base_cost(N, K, M, cars):
    max_base = -1
    for car in cars:
        # Upfront option
        upfront_cost = car.base - car.discount
        if upfront_cost <= K:
            max_base = max(max_base, car.base)
        
        # EMI option (only if duration <= M)
        emi_cost = car.emi * car.time
        if car.time <= M and emi_cost <= K:
            max_base = max(max_base, car.base)
    
    return max_base

# Input reading
N, K, M = map(int, input().split())
cars = []
for _ in range(N):
    base, emi, time, discount = map(int, input().split())
    cars.append(Car(base, emi, time, discount))

result = calculate_max_base_cost(N, K, M, cars)
print(result)
