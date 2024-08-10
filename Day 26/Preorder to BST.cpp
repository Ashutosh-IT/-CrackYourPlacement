/*

https://www.geeksforgeeks.org/problems/preorder-to-postorder4423/1

*/

class Solution {
  public:
  
    Node *create(int pre[], int size, int low, int high, int &index){
        
        if(index == size || pre[index] < low || pre[index] > high)
        return NULL;
        
        Node* root = newNode(pre[index++]);
        root->left = create(pre,size,low,root->data,index);
        root->right = create(pre,size,root->data,high,index);
        
        return root;
        
        
    }
    
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        int index = 0;
        return create(pre,size,INT_MIN,INT_MAX,index);
    }
};
