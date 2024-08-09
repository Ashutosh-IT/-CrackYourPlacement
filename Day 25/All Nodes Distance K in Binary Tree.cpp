/*

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

*/

class Solution {
public:

    void find(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent){
        if(!root) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;

        find(root->left,parent);
        find(root->right,parent);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;
        if(k==0) return {target->val};
        
        // find parent of all nodes so that we can traverse backward
        unordered_map<TreeNode*,TreeNode*> parent;
        find(root,parent);


        // use concept of graph : bfs traversal
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int distance = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
    
                if(temp->left && !visited[temp->left]) {
                    q.push(temp->left);
                    if(distance == k-1) ans.push_back(temp->left->val);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    if(distance == k-1) ans.push_back(temp->right->val);
                    visited[temp->right] = true;
                }
                if(temp != root && !visited[parent[temp]]){
                    q.push(parent[temp]);
                    if(distance == k-1) ans.push_back(parent[temp]->val);
                    visited[parent[temp]] = true;
                } 
            }
            distance++;

            if(distance == k) return ans;
        } 

        return {};
    }
};
