/*

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

*/

class Solution {
public:

    TreeNode* create(vector<int>& nums, int s, int e){
        if(s>e) return NULL;

        int mid = (s+e)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = create(nums,s,mid-1);
        root->right = create(nums,mid+1,e);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums,0,nums.size()-1);
    }
};
