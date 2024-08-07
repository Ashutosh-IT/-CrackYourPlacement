/*

https://leetcode.com/problems/maximum-width-of-binary-tree/description/

*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        int ans = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){

            int size = q.size();
            int mini = q.front().second;
            int first, last;

            for(int i=0; i<size; i++){
                TreeNode *temp = q.front().first;
                int index = q.front().second;
                index -= mini;
                if(i == 0) first = index;
                if(i == size-1) last = index;
                q.pop();

                if(temp->left) q.push({temp->left,(long long)2 * index});
                if(temp->right) q.push({temp->right,(long long)2 * index + 1});
            }
            ans = max(ans,last-first + 1);
        }

        return ans;
    }
};
