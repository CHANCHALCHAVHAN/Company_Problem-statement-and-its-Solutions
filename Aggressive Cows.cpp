/*
Farmer John has built a new long barn, with N (2 ≤ N ≤ 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 ≤ xi ≤ 1,000,000,000).

His C (2 ≤ C ≤ N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows.

Line 1: Two space-separated integers: N and C
Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.

Example
Input:
1
5 3
1
2
8
4
9

Output:
3
Explanation
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.


*/


// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int>&A,int n,int m , int mid){
    int cow=1 , lastpos=A[0];
    for(int i=1;i<n;i++){
        if((A[i]-lastpos)>=mid){
            cow++;
            lastpos=A[i];
        }
        if(cow==m){
            return true;
        }
    }
    return false;
}

int allocatePainters(vector<int> &A,int n,int m){
    sort(A.begin(),A.end());
    int ans=-1;
    int st=1, end=A[A.size()-1]-A[0] , mid=1;
    while(st<=end){
        mid=st+(end-st)/2;
        
        if(isValid(A,n,m,mid)){
            ans=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }
        
    }
    return ans;
}

int main() {
  vector<int> arr={1,2,8,4,9};
  int n=5, m=3;
  cout<< allocatePainters(arr,n,m)<<endl;
  return 0;
}
