/*

https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1

*/

class Solution {
  public:
  
    void find(Node *root, Node* &prev, Node* &head){
        if(!root) return;
        find(root->left,prev,head);
        
        if(prev == NULL){
            head = root;
            root->left = NULL;
        }
        else{
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        
        find(root->right,prev,head);
    }
    
    Node* bToDLL(Node* root) {
        
        Node *prev = NULL, *head = NULL;
        find(root,prev,head);
        
        return head;
    }
};
