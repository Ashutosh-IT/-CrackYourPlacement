/*

https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

*/

class Solution{
  public:
  
    void find(Node *root, int l, int r, bool &ans){
        if(ans) return;
        if(!root) return;
        
        if(!root->left && !root->right){
            if(root->data+1 == r && root->data-1 == l){
                ans = true;
                return;
            }
            else{
                return;
            }
        }
        
        find(root->left,l,root->data,ans);
        find(root->right,root->data,r,ans);
    }
    
    bool isDeadEnd(Node *root)
    {
        //Your code here
        bool ans = false;
        find(root,0,10002,ans);
        return ans;
    }
};
