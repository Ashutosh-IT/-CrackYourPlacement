/*

https://leetcode.com/problems/burst-balloons/description/

*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        vector<int> arr(n+2,1);

        for(int i=0; i<n; i++) arr[i+1] = nums[i];

        int dp[n+5][n+5];
        memset(dp,0,sizeof(dp));

        for(int i=1; i<=n; i++)
        dp[i][i] = arr[i-1]*arr[i]*arr[i+1];

        int length = 2;
        while(length <= n){
            for(int i=1; i<=n-length+1; i++){
                int j = i+length-1;
                dp[i][j] = 0;

                for(int k=i; k<=j; k++)
                dp[i][j] = max(dp[i][j], arr[k]*arr[i-1]*arr[j+1] + dp[i][k-1] + dp[k+1][j]);
            }
            length++;
        }
        

        return dp[1][n];
    }
};
