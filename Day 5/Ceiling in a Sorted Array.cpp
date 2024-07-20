/*

https://leetcode.com/problems/search-insert-position/description/

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();

        if(target > nums.back())
        return n;

        if(target <= nums[0])
        return 0;

        int s = 1;
        int e = n-1;

        while(s<=e){

            int mid = s+(e-s)/2;

            if(nums[mid] == target)
            return mid;

            else if(target > nums[mid])
            s = mid+1;

            else e = mid-1;

        }

        return s;
    
    }
};
