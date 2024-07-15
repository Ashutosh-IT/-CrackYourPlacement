/*

https://leetcode.com/problems/sort-colors/description/

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int s=0;
        int e=nums.size()-1;

        int i=0;
        while(i<=e){

            if(nums[i] == 2){
                swap(nums[i],nums[e]);
                e--;
            }
            else if(nums[i] == 1){
                i++;
            }
            else{
                if(i == s){
                    i++;
                    s++;
                }
                else{
                    swap(nums[i],nums[s]);
                    s++;
                }
            }
        }
    }
};
