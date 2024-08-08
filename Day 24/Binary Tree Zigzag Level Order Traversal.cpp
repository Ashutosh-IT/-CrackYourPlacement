/*

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;
        
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);

            for(int i=0; i<size; i++){
                TreeNode *temp = q.front();
                q.pop();

                // insert in vector
                if(flag){
                    row[i] = temp->val; 
                }
                else{
                    row[size-1-i] = temp->val;
                }

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            flag = !flag;
            ans.push_back(row);
        }

        return ans;

    }
};
