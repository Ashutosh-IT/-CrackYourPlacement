/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int ans = 0;
        int mini = prices[0];

        for(int i=1; i<n; i++){
            if(mini < prices[i]){
                ans += prices[i]-mini;
                mini = prices[i];
            }
            else mini = prices[i];
        }

        return ans;
    }
};
