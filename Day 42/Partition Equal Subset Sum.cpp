/*

https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1

*/

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++)
        sum += arr[i];
        
        if(sum&1) return 0;
        sum /= 2;
        
        int dp[N+1][sum+1];
        for(int i=0; i<=N; i++)
        dp[i][0] = 1;
        
        for(int j=1; j<=sum; j++)
        dp[0][j] = 0;
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                int opt1 = dp[i-1][j];
                int opt2 = j-arr[i-1] >= 0 ? dp[i-1][j-arr[i-1]] : 0;
                
                dp[i][j] = opt1 || opt2;
            }
        }
        
        return dp[N][sum];
        
    }
};
