/*

https://leetcode.com/problems/jump-game/description/

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int dp[n];
        dp[0] = 1;

        for(int i=1; i<n; i++){
            dp[i] = 0;
            for(int j=0; j<i; j++){
                int dist = i-j;
                if(nums[j] >= dist && dp[j]){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};
