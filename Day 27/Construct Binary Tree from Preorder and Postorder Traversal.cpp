/*

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

*/

class Solution {
public:

    int find(vector<int> &arr, int val){
        for(int i=0; i<arr.size(); i++)
        if(arr[i] == val) return i;

        return -1;
    }

    TreeNode *create(vector<int>& preorder, vector<int>& postorder, int s1, int e1, int s2, int e2){
        if(s1>e1 || s2>e2) return NULL;

        if(s1 == e1) return new TreeNode(preorder[s1]);

        TreeNode *root = new TreeNode(preorder[s1]);

        int index = find(preorder,postorder[e2-1]);
        int num = index-s1-1;
        root->left = create(preorder,postorder,s1+1,index-1,s2,s2+num-1);
        root->right = create(preorder,postorder,index,e1,s2+num,e2-1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        int n = preorder.size();

        return create(preorder,postorder,0,n-1,0,n-1);

    }
};
