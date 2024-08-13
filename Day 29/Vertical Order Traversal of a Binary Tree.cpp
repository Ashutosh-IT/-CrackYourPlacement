/*

https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

*/

class Solution {
public:

    void findLR(TreeNode *root, int &l, int &r, int index){
        if(!root) return;

        l = min(l,index);
        r = max(r,index);

        findLR(root->left,l,r,index-1);
        findLR(root->right,l,r,index+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        int l = 0;
        int r = 0;
        findLR(root,l,r,0);

        int n = r-l + 1;

        vector<vector<int>> ans(n);
        queue<pair<TreeNode*,int>> q;
        q.push({root,abs(l)});

        while(!q.empty()){
            int size = q.size();
            unordered_map<int,int> mp;

            while(size--){
                TreeNode *temp = q.front().first;
                int index = q.front().second;
                q.pop();

                ans[index].push_back(temp->val);
                mp[index]++;

                if(temp->left) q.push({temp->left,index-1});
                if(temp->right) q.push({temp->right,index+1});
            }

            for(int i=0; i<n; i++)
            if(mp[i] > 1){
                int sz = ans[i].size();
                int st = sz-mp[i];
                sort(ans[i].begin()+st, ans[i].end());
            }
        }

        return ans;

    }
};
