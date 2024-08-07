/*

https://leetcode.com/problems/binary-tree-right-side-view/description/

*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(!root) return ans;
        
        // level order traversal
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode *temp = q.front();
                q.pop();

                 // then pick last node from every level
                if(size == 0) ans.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }

        return ans;
    }
};
