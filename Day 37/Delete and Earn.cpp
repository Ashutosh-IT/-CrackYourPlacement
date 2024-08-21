class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int dp[n];

        int ans = nums[0];
        dp[0] = nums[0];

        if(n==1) return dp[0];

        dp[1] = nums[1] - nums[0] == 1 ? nums[1] : nums[1] + nums[0];
        ans = max(dp[0],dp[1]);


        for(int i=2; i<n; i++){
            int num = nums[i];

            dp[i] = num;
            int j = i-1;

            while(j>=0){
                if(num-nums[j] != 1){
                    dp[i] = max(dp[i],num+dp[j]);
                }
                j--;
            }
            ans = max(ans,dp[i]);
        }

        return ans;
    }
};
