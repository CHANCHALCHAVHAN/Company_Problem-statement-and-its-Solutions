/*
Problem Statement
A startup company is responsible for managing salary payments to its employees from its bank account. Each employee has a designated salary, and the company needs to verify if it can pay these salaries sequentially based on the current balance in its account.
Your task is to assess whether the company can disburse each employee's salary in the given order while updating the balance accordingly. If a payment can be made, the balance should be decreased by the salary amount; if it cannot be paid, the company should return false for that employee, and the balance will remain unchanged.

Input Format
The first line of input contains an integer value N representing the amount of money in the company's bank account.
The second line contains an integer M, which indicates the number of employees.
The third line features an array of employee names as strings, separated by spaces.
The fourth line contains an array of M integers representing the salary for each employee, separated by spaces.

Output Format
Output a series of true or false values corresponding to each employee, indicating whether the salary for that employee can be paid:

true if the salary can be paid.
false if the salary cannot be paid.
Each value should be separated by spaces.

Constraints
0<= N < 10^6
1< M < 10^2

Sample Testcase 0
Testcase Input
100000
3
employee1 employee2 employee3 
50000 50000 60000
Testcase Output
true true false
Explanation
For employee1, the salary is 50000, which is less than the initial balance of 100000. The balance is updated to 50000 after paying the salary, and the output is true.


For employee2, the salary is 50000, which is less than the updated balance of 50000. The balance is updated to 0 after paying the salary, and the output is true.


For employee3, the salary is 60000, which is more than the updated balance of 0. Therefore, the output is false.

Sample Testcase 1
Testcase Input
50000
5
employee1 employee2 employee3 employee4 employee5
54000 10000 60000 20000 5000
Testcase Output
false true false true true
Explanation
For employee1, the salary is 54000, which is more than the initial balance of 50000. Therefore, the output is false.


For employee2, the salary is 10000, which is less than the current balance of 50000. The balance is updated to 40000 after paying the salary, and the output is true.


For employee3, the salary is 60000, which is more than the updated balance of 40000. Therefore, the output is false.


For employee4, the salary is 20000, which is less than the updated balance of 40000. The balance is updated to 20000 after paying the salary, and the output is true.


For employee5, the salary is 5000, which is less than the updated balance of 20000. The balance is updated to 15000 after paying the salary, and the output is true.

Companies
Amazon
Atlassian
Barclays
Topics
Array
Greedy
Math

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> can_pay_salaries(int company_money, int employee_count ,vector<string> employee_names, vector<int> employee_salaries) {
    // Write your logic here.
    vector <bool> result;
    int balance = company_money;
    for(int i=0 ; i< employee_count ; i++){
        if (employee_salaries[i]<= balance){
            balance -= employee_salaries[i];
            result.push_back(true);
        }
        else{
            result.push_back(false);
        }
    }
    return vector<bool>();
}

int main() {
    int company_money;
    int employee_count;
    cin >> company_money >> employee_count;
    vector<string> employee_names(employee_count);
    for (int i = 0; i < employee_count; ++i) {
        cin >> employee_names[i];
    }
    vector<int> employee_salaries(employee_count);
    for (int i = 0; i < employee_count; ++i) {
        cin >> employee_salaries[i];
    }

    vector<bool> result = can_pay_salaries(company_money,employee_count, employee_names, employee_salaries);

    for (bool can_pay : result) {
        cout << (can_pay ? "true" : "false") << " ";
    }

    return 0;
}
