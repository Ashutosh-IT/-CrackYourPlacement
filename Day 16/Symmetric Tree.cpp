/*

https://leetcode.com/problems/symmetric-tree/description/

*/

class Solution {
public:

    bool same(TreeNode *root1, TreeNode *root2){

        if(!root1 && !root2) return true;
        if(!root1) return false;
        if(!root2) return false;

        if(root1->val != root2->val) return false;

        return same(root1->left,root2->right) && same(root1->right,root2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return same(root->left,root->right);
    }
};
