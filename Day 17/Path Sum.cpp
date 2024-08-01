/*

https://leetcode.com/problems/path-sum/description/

*/

class Solution {
public:
    
    void find(TreeNode *root, int sum, int target, bool &ans){
        if(ans) return;  
        if(!root) return;
        
        if(!root->left && !root->right){
            if(sum==target) ans = true;
            return;
        }
      
        if(root->left)
        find(root->left,sum+root->left->val,target,ans);
        
        if(root->right)
        find(root->right,sum+root->right->val,target,ans);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        bool ans = false;
        find(root,root->val,targetSum,ans);
        return ans;
    }
    
};
