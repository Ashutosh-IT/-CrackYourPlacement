/*

https://leetcode.com/problems/3sum/

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        set<vector<int>> st;

        sort(nums.begin(),nums.end());

        for(int i=0; i<=n-3; i++){
            int s=i+1;
            int e=n-1;

            while(s<e){
                int sum = nums[i] + nums[s] + nums[e];
                if(sum == 0){
                    st.insert({nums[i],nums[s],nums[e]});
                    e--;
                }
                else if(sum > 0) e--;
                else s++;
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans; 
    }
};
