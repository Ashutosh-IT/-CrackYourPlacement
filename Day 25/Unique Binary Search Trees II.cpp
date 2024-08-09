/*

https://leetcode.com/problems/unique-binary-search-trees-ii/description/

*/



// Approach 1 : only using recursion
class Solution {
public:
    vector<TreeNode*> solve(int s, int e){

        if(s>e){
            return {NULL};
        }

        if(s==e){
            TreeNode* root = new TreeNode(s);
            return {root};
        }
        
        vector<TreeNode*> ans;

        for(int i=s; i<=e; i++){
            vector<TreeNode*> left = solve(s,i-1);
            vector<TreeNode*> right = solve(i+1,e);

            for(int j=0; j<left.size(); j++){
                for(int k=0; k<right.size(); k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};



// Approach 2 : using memoization
class Solution {
public:
    map<pair<int,int>,vector<TreeNode*>> mp;
    vector<TreeNode*> solve(int s, int e){

        if(s>e){
            return {NULL};
        }

        if(s==e){
            TreeNode* root = new TreeNode(s);
            return {root};
        }

        if(mp.find({s,e}) != mp.end())
        return mp[{s,e}];
        
        vector<TreeNode*> ans;

        for(int i=s; i<=e; i++){
            vector<TreeNode*> left = solve(s,i-1);
            vector<TreeNode*> right = solve(i+1,e);

            for(int j=0; j<left.size(); j++){
                for(int k=0; k<right.size(); k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }

        mp[{s,e}] = ans;
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};
