/*

https://www.geeksforgeeks.org/problems/median-of-bst/1

*/

void inorder(Node *root, vector<int> &ans){
    if(!root) return;
    
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
    
}

float findMedian(struct Node *root)
{
      //Code here
      vector<int> ans;
      inorder(root,ans);
      int size = ans.size();
      
      if(size % 2 == 1){
          return ans[size/2];
      }
      
      return (ans[size/2] + ans[size/2 - 1])/2.0; 
}
