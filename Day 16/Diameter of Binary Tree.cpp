/*

https://leetcode.com/problems/diameter-of-binary-tree/description/

*/

class Solution {
public:

    int find(TreeNode *root, int &ans){
        if(!root) return 0;

        int left = find(root->left,ans);
        int right = find(root->right,ans);

        ans = max(ans,left+right);

        return max(left+1,right+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        find(root,ans);
        return ans;
    }
};
