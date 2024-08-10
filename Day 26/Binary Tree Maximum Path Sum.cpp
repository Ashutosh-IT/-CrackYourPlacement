/*

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

*/

class Solution {
public:

    int find(TreeNode* root, int &ans){
        if(!root) return 0;

        int l = find(root->left,ans);
        if(l<0) l=0;

        int r = find(root->right,ans);
        if(r<0) r=0;

        ans = max(ans,root->val + l + r);
        return max(l,r) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        find(root,ans);
        return ans;
    }
};
