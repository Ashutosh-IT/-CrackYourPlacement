/*

https://www.geeksforgeeks.org/problems/aggressive-cows/0

*/

class Solution {
public:

    bool possible(vector<int> &stalls, int n, int k, int mid){
        int cows = 1;
        int prev = stalls[0];
        for(int i=1; i<n; i++){
            int diff = stalls[i] - prev;
            if(diff >= mid){
                cows++;
                prev = stalls[i];
            }
        }
        
        return cows>=k;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        
        int s=1;
        int e=stalls[n-1]-stalls[0];
        int ans = -1;
        
        while(s <= e){
            int mid = s+(e-s)/2;
            
            if(possible(stalls,n,k,mid)){
                ans = mid;
                s = mid+1;
            }
            else e=mid-1;
        }
        
        return ans;
    }
