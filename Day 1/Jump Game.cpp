/*

https://leetcode.com/problems/jump-game/description/

*/


// TC -> O(N^2) 
// SC -> O(N)
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



// TC -> O(N) 
// SC -> O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;

        int maxIdx = nums[0];
        for(int i=0; i<n; i++){

            if(maxIdx >= n-1) return true;
            if(maxIdx == i && nums[i] == 0) return false;
            if(nums[i] + i > maxIdx) maxIdx = i + nums[i];

        }

        return true;
    }

};
