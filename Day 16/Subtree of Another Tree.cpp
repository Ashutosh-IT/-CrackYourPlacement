/*

https://leetcode.com/problems/subtree-of-another-tree/description/

*/

class Solution {
public:

    bool same(TreeNode *root1, TreeNode *root2){

        if(!root1 && !root2) return true;
        else if(!root1) return false;
        else if(!root2) return false;

        if(root1->val != root2->val) return false;

        return same(root1->left,root2->left) && same(root1->right,root2->right);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val == subRoot->val){
            if(same(root,subRoot)) return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
