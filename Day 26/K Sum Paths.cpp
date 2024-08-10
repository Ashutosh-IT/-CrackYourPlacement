/*

https://www.geeksforgeeks.org/problems/k-sum-paths/1

*/

class Solution {
  public:
  
    void find(Node *root, int k, unordered_map<int,int> &mp, int &ans, int &sum){
        if(!root) return;
        
        sum += root->data;
        ans += mp[sum-k];
        
        mp[sum]++;
        
        find(root->left,k,mp,ans,sum);
        find(root->right,k,mp,ans,sum);
        
        mp[sum]--;
        sum -= root->data;
    }
    
    int sumK(Node *root, int k) {
        // code here
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        find(root,k,mp,ans,sum);
        
        return ans;
    }
};
