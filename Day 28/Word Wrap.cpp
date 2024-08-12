/*

https://www.geeksforgeeks.org/problems/word-wrap1646/1

*/

class Solution {
public:

    
    int solve(vector<int> &nums, int k, int index, int rem, int dp[505][2005]){
        if(index == nums.size()) return 0;
        
        if(dp[index][rem] != -1) return dp[index][rem];
        
        // case 1 : word remaining spaces se jyada hai
        if(nums[index] > rem) 
        return (rem+1)*(rem+1) + solve(nums,k,index+1,k-nums[index]-1,dp);
        
        
        // case 2 : word remaining spaces me fit ho skta hai
        int opt1 = (rem+1)*(rem+1) + solve(nums,k,index+1,k-nums[index]-1,dp); // put in another line
        int opt2 = solve(nums,k,index+1,rem-nums[index]-1,dp);
        
        return dp[index][rem] = min(opt1,opt2);
        
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int dp[505][2005];
        memset(dp,-1,sizeof(dp));
        return solve(nums,k,0,k,dp);
        
    } 
};
