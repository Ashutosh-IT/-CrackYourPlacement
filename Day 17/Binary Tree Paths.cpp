/*

https://leetcode.com/problems/binary-tree-paths/description/

*/

class Solution {
public:
    
    void find(TreeNode* root, string &temp, vector<string> &ans){
        if(!root) return;
        
        if(!root->right && !root->left){
            ans.push_back(temp);
            return;
        }
        
        if(root->left){
            temp += "->";
            string s = to_string(root->left->val);
            temp += s;
            find(root->left,temp,ans);
            while(s.size()){
                s.pop_back();
                temp.pop_back();
            }

            temp.pop_back();
            temp.pop_back();
        }
        
        if(root->right){
            temp += "->";
            string s = to_string(root->right->val);
            temp += s;
            find(root->right,temp,ans);

            while(s.size()){
                s.pop_back();
                temp.pop_back();
            }
            temp.pop_back();
            temp.pop_back();
        }
        
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string temp = "";
        temp += (to_string(root->val));
        vector<string> ans;
        find(root,temp,ans);
        return ans;
    }
};
