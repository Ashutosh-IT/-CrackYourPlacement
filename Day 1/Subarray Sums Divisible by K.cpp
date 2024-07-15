/*

https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;

        int ans = 0;
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            int num = sum % k;
            num = num<0 ? num+k : num;
            ans += mp[num];
            mp[num]++;
        }

        return ans;

    }
};
