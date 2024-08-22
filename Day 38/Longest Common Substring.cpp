/*

https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

*/


class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();
        
        int dp[n][m];
        int ans = 0;
        
        for(int i=0; i<n; i++){
            dp[i][0] = str1[i] == str2[0];
            ans = max(ans,dp[i][0]);
        }
        
        
        for(int j=0; j<m; j++){
            dp[0][j] = str1[0] == str2[j];
            ans = max(ans,dp[0][j]);
        }
      
        
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                
                //case1 : character not matches
                if(str1[i] != str2[j])
                dp[i][j] = 0;
                
                
                // case2 : character matches
                else{
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans,dp[i][j]);
                }
                
            }
        }
        
        
        return ans;
        
    }
};
