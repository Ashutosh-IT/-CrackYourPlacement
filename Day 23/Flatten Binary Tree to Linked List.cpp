/*

https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        TreeNode *temp = root;
        while(temp){
            if(temp->left){
                TreeNode *right = temp->right;
                temp->right = temp->left;
                temp->left = NULL;
                TreeNode *temp1 = temp->right;
                while(temp1->right) temp1 = temp1->right;
                temp1->right = right;
            }

            temp = temp->right;
        }
    }
};
