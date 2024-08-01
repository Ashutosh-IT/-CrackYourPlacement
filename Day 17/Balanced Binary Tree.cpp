/*

https://leetcode.com/problems/balanced-binary-tree/description/

*/

class Solution {
public:

    int find(TreeNode *root, bool &ans){
        if(!ans) return 0;
        if(!root) return 0;

        int l = find(root->left,ans);
        int r = find(root->right,ans);

        if(abs(l-r) > 1){
            ans = false;
        }

        return max(l,r) + 1;

    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        find(root,ans);
        return ans;
    }
};
