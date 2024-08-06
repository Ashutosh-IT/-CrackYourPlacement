/*

https://leetcode.com/problems/validate-binary-search-tree/

*/

class Solution {
public:

    void find(TreeNode* root, bool &ans, int &prev, bool &flag){
        if(!root) return;
        if(!ans) return;

        find(root->left,ans,prev,flag);
        if(!flag && root->val <= prev){
            ans = false;
            return;
        }
        flag = false;
        prev = root->val;
        find(root->right,ans,prev,flag);
    }

    bool isValidBST(TreeNode* root) {
        bool ans = true;
        bool flag = true;
        int prev = INT_MIN;
        find(root,ans,prev,flag);
        return ans;
    }
};
