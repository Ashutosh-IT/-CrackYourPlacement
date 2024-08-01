/*

https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

*/

class Solution {
public:
    void find(TreeNode *root, int &prev, int &ans){
        if(!root) return;
        
        find(root->left,prev,ans);
        ans = min(ans,abs(prev-root->val));
        prev = root->val;
        find(root->right,prev,ans);             
        
    }
      
    int getMinimumDifference(TreeNode* root) {
        
        int ans = INT_MAX;
        int prev = INT_MAX;
        find(root,prev,ans);
        return ans;
    }
};
