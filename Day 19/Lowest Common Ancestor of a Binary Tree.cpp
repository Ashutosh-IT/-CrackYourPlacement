/*

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

*/

class Solution {
public:

    void find(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> &temp, vector<TreeNode*> &path1, vector<TreeNode*> &path2){
        if(!root) return;

        if(root == p) path1 = temp;
        if(root == q) path2 = temp;

        if(root->left){
            temp.push_back(root->left);
            find(root->left,p,q,temp,path1,path2);
            temp.pop_back();
        }

        if(root->right){
            temp.push_back(root->right);
            find(root->right,p,q,temp,path1,path2);
            temp.pop_back();
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        vector<TreeNode*> temp;
        temp.push_back(root);
        vector<TreeNode*> path1, path2;
        find(root,p,q,temp,path1,path2);

        TreeNode *ans = NULL;
        int i=0, j=0;
        while(i<path1.size() && j<path2.size()){
            if(path1[i] == path2[j++])
            ans = path1[i++];
        }

        return ans;
    }
};
