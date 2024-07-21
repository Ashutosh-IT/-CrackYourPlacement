/*

https://leetcode.com/problems/search-in-rotated-sorted-array/description/

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        if(nums[0] == target) return 0;
        if(nums[n-1] == target) return n-1;

        int s=1;
        int e=n-2;

        while(s <= e){
            int mid = s+(e-s)/2;

            if(nums[mid] == target)
            return mid;

            else if(nums[mid] >= nums[0]){
                if(target > nums[0] && target < nums[mid])
                e = mid-1;
                else s = mid+1;
            }

            else{
                if(target < nums[n-1] && target > nums[mid])
                s = mid+1;
                else e = mid-1;
            }
        }
        
        return -1;
    }
};
