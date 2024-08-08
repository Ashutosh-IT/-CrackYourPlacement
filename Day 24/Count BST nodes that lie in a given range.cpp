/*

https://www.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

*/

class Solution{
public:


    void find(Node *root, int l, int r, int &count){
        if(!root) return;
        
        if(root->data >= l && root->data <= r)
        count++;
        
        find(root->left,l,r,count);
        find(root->right,l,r,count);
    }
    
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      
      int count = 0;
      find(root,l,h,count);
      return count;
      
    }
};
