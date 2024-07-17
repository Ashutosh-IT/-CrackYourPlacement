/*

https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/0

*/

class Solution {
  public:
  
    vector<vector<int>> ans;
    
    void find(vector<int> &arr, int n, int idx){
        if(idx == n){
            ans.push_back(arr);
            return;
        }
        
        
        vector<bool> used(10,0);
        for(int i=idx; i<n; i++){
            if(!used[arr[i]]){
                used[arr[i]] = 1;
                swap(arr[i],arr[idx]);
                find(arr,n,idx+1);
                swap(arr[i],arr[idx]);
            }
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        find(arr,n,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
