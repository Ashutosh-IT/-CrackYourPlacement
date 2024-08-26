/*

https://leetcode.com/problems/trapping-rain-water/

*/

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        if(n<=2) return 0;

        int l = 1;
        int r = n-1;

        int leftMax = height[0];
        int rightMax = height.back();

        int ans = 0;

        while(l<=r){
            leftMax = max(leftMax,height[l]);
            rightMax = max(rightMax,height[r]);

            if(leftMax < rightMax)
            ans += (leftMax - height[l++]);

            else ans += (rightMax - height[r--]);
        }
        
        return ans;
    }
};
