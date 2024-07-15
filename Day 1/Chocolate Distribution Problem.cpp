/*

https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

*/

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        sort(a.begin(),a.end());
        long long ans = 1e9;
        
        long long i=0;
        while(i <= n-m){
            long long j=i+m-1;
            ans = min(ans,a[j]-a[i]);
            i++;
        }
        
        return ans;
    
    }   
};
