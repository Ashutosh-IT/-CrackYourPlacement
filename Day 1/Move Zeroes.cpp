/*

https://leetcode.com/problems/move-zeroes/description/

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();

        int count = 0;
        int index = 0;

        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                nums[index] = nums[i];
                index++;
            }
            else count++;
        }

        int i=n-1;
        while(count--)
        nums[i--] = 0;

    }
};
