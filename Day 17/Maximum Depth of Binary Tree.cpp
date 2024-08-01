/*

https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

*/

class Solution {
public:
    
    
    void find(TreeNode* root, int &ans, int h){
        if(!root) return;
        ans = max(ans,h);
        
        find(root->left,ans,h+1);
        find(root->right,ans,h+1);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int ans = 1;
        
        find(root,ans,1);
        return ans;
        
    }
};
