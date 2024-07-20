/*

https://www.geeksforgeeks.org/permute-two-arrays-sum-every-pair-greater-equal-k/

*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    
    int a[n], b[n];
    for(int i=0; i<n; i++)
    cin>>a[i]>>b[i];
    
    sort(a,a+n);
    sort(b,b+n,greater<int>());
    
    for(int i=0; i<n; i++)
    if(a[i]+b[i]<k){
        cout<<"NO";
        break;
    }
    
    cout<<"YES";
    
}
