/*

https://leetcode.com/problems/distinct-subsequences/description/

*/

class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        int mod = 1e9+7;

        vector<vector<int>> dp(n,vector<int>(m,0));

        // base cases
        dp[0][0] = s[0] == t[0] ? 1 : 0;

        for(int j=1; j<m; j++)
        dp[0][j] = 0;    
        

        for(int i=1; i<n; i++)
        dp[i][0] = s[i] == t[0] ? dp[i-1][0] + 1 : dp[i-1][0];


        // fill dp array
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){

                if(i<j){
                    dp[i][j] = 0;
                    continue;
                }

                // case1 : character matched
                if(s[i] == t[j])
                dp[i][j] = (dp[i-1][j-1]%mod + dp[i-1][j]%mod)%mod;


                // case2 : character not matched
                else 
                dp[i][j] = dp[i-1][j];
            }
        }



        // return ans
        return dp[n-1][m-1];
    }
};
