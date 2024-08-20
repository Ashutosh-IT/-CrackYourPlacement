/*

https://leetcode.com/problems/maximum-product-subarray/

*/


class Solution {
public:

    int mod = INT_MAX;

    int maxProduct(vector<int>& nums) {
        long long ans = INT_MIN;
        long long product = 1;


        // kadane algorithm from front
        for(int i=0; i<nums.size(); i++){
            product *= nums[i];
            product %= mod;
            ans = max(ans,product);

            if(product == 0) product = 1;
        }


        // kadane algorithm from back
        product = 1;
        for(int i=nums.size()-1; i>=0; i--){
            product *= nums[i];
            product %= mod;
            ans = max(ans,product);

            if(product == 0) product = 1;
        }


        return ans;
    }
};
