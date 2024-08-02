/*

https://leetcode.com/problems/binary-tree-inorder-traversal/description/

*/

class Solution {
public:

    void find(vector<int> &ans, TreeNode *root){
        if(!root) return;
        find(ans,root->left);
        ans.push_back(root->val);
        find(ans,root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {    
        vector<int> ans;
        find(ans,root);
        return ans;
    }

};
