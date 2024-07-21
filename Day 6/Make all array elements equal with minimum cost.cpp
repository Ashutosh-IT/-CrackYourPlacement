/*

https://www.geeksforgeeks.org/make-array-elements-equal-minimum-cost/

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];
    
    if(n==1) return 0;
    
    sort(arr,arr+n);
    int middle = 0;
    
    if(n&1) middle = arr[n/2];
    else{
        middle = (arr[n/2] + arr[(n-1)/2])/2;
    }
    
    int ans = 0;
    for(int i=0; i<n; i++)
    ans += abs(middle-arr[i]);
    
    cout<<ans;
    
}
