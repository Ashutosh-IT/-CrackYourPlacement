/*

https://leetcode.com/problems/longest-increasing-subsequence/description/

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        int ans = 1;

        int dp[n];
        dp[0] = 1;
        if(n>1) dp[1] = nums[0] < nums[1] ? 2 : 1;
        if(n>1) ans = max(ans,dp[1]);

    

        for(int i=2; i<n; i++){
            dp[i] = 1;
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        } 

        return ans;
    }
};
