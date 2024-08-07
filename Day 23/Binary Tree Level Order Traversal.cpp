/*

https://leetcode.com/problems/binary-tree-level-order-traversal/description/

*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        // level order traversal
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> row;
            int size = q.size();
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                row.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
