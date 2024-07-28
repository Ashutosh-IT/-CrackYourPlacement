/*

https://leetcode.com/problems/sum-of-subarray-minimums/description/

*/


// Brute force - O(n^2)
class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            int mini = INT_MAX;
            for(int j=i; j<n; j++){
                mini = min(mini,arr[j]);
                sum = (sum%mod + mini%mod)%mod;
            }
        }

        return sum;
    }
};

