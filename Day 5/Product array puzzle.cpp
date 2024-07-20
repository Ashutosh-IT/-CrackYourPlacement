/*

https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1

*/

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here    
        vector<long long> ans(n,1);
        
        for(int i=1; i<n; i++)
        ans[i] = ans[i-1]*nums[i-1];
        
        long long product = 1;
        
        for(int i=n-2; i>=0; i--){
            product *= nums[i+1];
            ans[i] *= product;
        }
        
        return ans;
        
    }
};
