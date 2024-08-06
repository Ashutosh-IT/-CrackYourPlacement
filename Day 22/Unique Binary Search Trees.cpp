/*

https://leetcode.com/problems/unique-binary-search-trees/description/

*/

class Solution {
public:
    int numTrees(int n) {
        
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;

        // fill dp array
        for(int i=2; i<=n; i++){
            // take each node as root
            for(int j=1; j<=i; j++){
                dp[i] += (dp[j-1] * dp[i-j]);
            }
        }

        // return ans
        return dp[n];
    }
};
