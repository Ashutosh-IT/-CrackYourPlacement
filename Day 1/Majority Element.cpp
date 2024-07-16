/*

https://leetcode.com/problems/majority-element/

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        int count = 1;
        int ele = nums[0];

        for(int i=0; i<n; i++){
            if(nums[i] == ele)
            count++;

            else{
                count--;
                if(count == 0){
                    count = 1;
                    ele = nums[i];
                }
            }
        }

        return ele;
    }
};
