/*

https://www.geeksforgeeks.org/problems/cutted-segments1642/1

*/

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        if(n<x && n<y && n<z) return 0;
        
        int dp[n+1];
        // dp[i] = best possible answer such that line is of length i
        
        dp[0] = 0;
        dp[1] = x==1 || y==1 || z==1 ? 1 : 0;
        
        for(int i=2; i<=n; i++){
            int opt1 = x == i ? 1 : (i-x < 0 ? 0 : (dp[i-x] == 0 ? 0 : dp[i-x] + 1));
            int opt2 = y == i ? 1 : (i-y < 0 ? 0 : (dp[i-y] == 0 ? 0 : dp[i-y] + 1));
            int opt3 = z == i ? 1 : (i-z < 0 ? 0 : (dp[i-z] == 0 ? 0 : dp[i-z] + 1));
            
            dp[i] = max(opt1,max(opt2,opt3));
        }
        
        return dp[n];
    }
};
