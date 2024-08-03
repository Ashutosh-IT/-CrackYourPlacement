/*

https://leetcode.com/problems/binary-search-tree-iterator/description/

*/

class BSTIterator {
public:

    vector<int> inorder;
    int size;
    int index;

    void find(TreeNode* root){
        if(!root) return;
        find(root->left);
        inorder.push_back(root->val);
        find(root->right);
    }

    BSTIterator(TreeNode* root) {
        find(root);
        size = inorder.size();
        index = 0;
    }
    
    int next() {
        return inorder[index++];
    }
    
    bool hasNext() {
        return index != size;
    }
};
