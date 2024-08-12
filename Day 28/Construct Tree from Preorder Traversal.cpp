/*

https://www.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1

*/


Node* create(int n, int pre[], char preLN[], int &index){
    if(index >= n) return NULL;
    
    Node* root = new Node(pre[index]);
    if(preLN[index++] == 'L') return root;
    
    root->left = create(n,pre,preLN,index);
    root->right = create(n,pre,preLN,index);
    
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int index = 0;
    return create(n,pre,preLN,index);
}
