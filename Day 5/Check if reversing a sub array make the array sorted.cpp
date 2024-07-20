/*

https://www.geeksforgeeks.org/check-reversing-sub-array-make-array-sorted/

*/

#include<bits/stdc++.h>
using namespace std;

bool find(int arr[], int n){
    
    if(n == 1) return true;
    int i = n-2;
  
    while(i>=0 && arr[i+1] >= arr[i]) i--;
    if(i == -1) return true;
  
	  int end = i+1;
  
    while(i>=0 && arr[i+1] <= arr[i]) i--;
    if(i == -1) return true;
  
    if(arr[i]>arr[end]) return false;
    
    while(i>0){
        if(arr[i] < arr[i-1])
        return false;
        i--;
    }
    
    return true;
}

int main(){
	
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];
    
    cout<<find(arr,n);
    
}
