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


// without using set :

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int i=0; i<=n-3; i++){

            // skips duplicates for 1st element
            if(i>0 && nums[i] == nums[i-1]) continue;

            int s=i+1;
            int e=n-1;

            while(s<e){
                int sum = nums[i] + nums[s] + nums[e];
                if(sum == 0){
                    ans.push_back({nums[i],nums[s],nums[e]});
                    s++;
                    e--;

                    // skips duplicate for 2nd element
                    while(s<e && nums[s] == nums[s-1]) s++;

                    // skips duplicates for 3rd element
                    while(s<e && nums[e] == nums[e+1]) e--;
                    
                }
                else if(sum > 0) e--;
                else s++;
            }
        }

        return ans; 
    }
};
