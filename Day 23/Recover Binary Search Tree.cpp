/*

https://leetcode.com/problems/recover-binary-search-tree/description/

*/


// Approach 1 : using O(n) space
class Solution {
public:

    void inorder(TreeNode *root, vector<int> &ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans); 
    }

    void create(TreeNode *root, vector<int> &ans, int &index){
        if(!root) return;
        create(root->left,ans,index);
        root->val = ans[index++];
        create(root->right,ans,index);
    }

    void recoverTree(TreeNode* root) {

        // find inorder traversal
        vector<int> ans;
        inorder(root,ans);

        // then check the array for wrong numbers;
        int num1 = -1;
        int num2 = -1;
        for(int i=1; i<ans.size(); i++){
            if(ans[i] < ans[i-1]){
                num1 = num1 != -1 ? num1 : i-1;
                num2 = i;
            }
        }
        swap(ans[num1],ans[num2]);
      
        int index = 0;
        create(root,ans,index);
        
    }
};



// Approach 2 : using O(1) space
class Solution {
public:

    void inorder(TreeNode *root, TreeNode* &first, TreeNode* &second, TreeNode* &prev, bool &flag){
        if(!root) return;

        inorder(root->left,first,second,prev,flag);

        if(flag){
            prev = root;
            flag = false;
        }
        else{
            if(prev->val > root->val){
                first = first == NULL ? prev : first;
                second = root;
            }
            prev = root;
        }

        inorder(root->right,first,second,prev,flag);
    }

    void recoverTree(TreeNode* root) {
        
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;

        bool flag = true;

        inorder(root,first,second,prev,flag);

        swap(first->val,second->val);
    }
};
