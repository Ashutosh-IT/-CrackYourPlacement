/*

https://leetcode.com/problems/split-array-largest-sum/description/

*/

class Solution {
public:

    bool possible(vector<int> &nums, int n, int k, int mid){
        int parts = 1;
        int sum = nums[0];

        for(int i=1; i<n; i++){
            sum += nums[i];
            if(sum >mid){
                sum = nums[i];
                parts++;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        int maxi = nums[0];
        int sum = nums[0];
        for(int i=1; i<n; i++){
            maxi = max(maxi,nums[i]);
            sum += nums[i];
        }

        int s = maxi;
        int e = sum;
        int ans = -1;

        while(s <= e){
            int mid = s+(e-s)/2;

            if(possible(nums,n,k,mid)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }

        return ans;
    }
};
