/*

https://leetcode.com/problems/range-sum-of-bst/description/

*/


class Solution {
public:

    void find(TreeNode *root, int low, int high, int &sum){
        if(!root) return;

        if(root->val >= low && root->val <= high){
            sum += root->val;
            find(root->left,low,high,sum);
            find(root->right,low,high,sum);
        }

        else if(root->val < low){
            find(root->right,low,high,sum);
        }

        else if(root->val > high){
            find(root->left,low,high,sum);
        }
        
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        find(root,low,high,sum);
        return sum;
    }
};
