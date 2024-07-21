/*

https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

*/

class Solution {
  public:
  
    bool possible(int arr[], int n, int m, long long mid){
        int count = 1;
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum > mid){
                count++;
                sum = arr[i];
            }
        }
        
        return count <= m;
    }
    
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m>n) return -1;
        
        int maxi = arr[0];
        long long sum = arr[0];
        
        for(int i=1; i<n; i++){
            maxi = max(maxi,arr[i]);
            sum += arr[i];
        }
        
        long long s=maxi;
        long long e=sum;
        long long ans = -1;
        
        while(s <= e){
            long long mid = s+(e-s)/2;
            if(possible(arr,n,m,mid)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        
        return ans;
    }
};
