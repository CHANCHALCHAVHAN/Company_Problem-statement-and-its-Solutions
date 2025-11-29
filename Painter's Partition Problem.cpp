/*
Painter's Partition Problem

Given are N boards of length of each given in the form of array, and Mpainters, such
that each painter takes 1 unit of time to paint 1 unit of the board.

The task is to find the minimum time to paint all boards under the constraints that any
painter will only paint continuous sections of boards
*/

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>&A,int n,int m , int mid){
    int pt=1 , PtB=0;
    for(int i=0;i<A.size();i++){
        if(A[i]>mid){
            return false;
        }
        if(PtB+A[i]<=mid){
            PtB+=A[i];
        }
        else{
            pt++;
            PtB=A[i];
        }
    }
    return pt>m ? false:true;
}

int allocatePainters(vector<int> &A,int n,int m){
    int sum=0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
    }
    int ans=-1;
    int st=0, end=sum , mid=1;
    while(st<=end){
        mid=st+(end-st)/2;
        
        if(isValid(A,n,m,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            st=mid+1;
        }
        
    }
    return ans;
}

int main() {
  vector<int> arr={30,40,60,20,10};
  int n=4, m=2;
  cout<< allocatePainters(arr,n,m)<<endl;
  return 0;
}
