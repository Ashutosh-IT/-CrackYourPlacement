/*

https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

*/

class Solution {
public:

    void find(TreeNode* root, int k, int &count, int &ans){
        if(!root) return;
        if(ans != -1) return;

        find(root->left,k,count,ans);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        find(root->right,k,count,ans);

    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = -1;
        find(root,k,count,ans);
        return ans;
    }
};
