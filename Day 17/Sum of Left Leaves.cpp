/*

https://leetcode.com/problems/sum-of-left-leaves/description/

*/

class Solution {
public:

    void find(TreeNode* root, int &sum, bool left){
        if(!root) return;

        if(left && !root->left && !root->right)
        sum += root->val;
        
        find(root->left,sum,true);
        find(root->right,sum,false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        find(root,sum,false);
        return sum;
    }
};
