/*

https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

*/

class Solution{
    public:
    
    
    void find(Node *root, int a, int b, string &path1, string &path2, string &temp){
        if(!root) return;
        
        if(root->data == a) path1 = temp;
        if(root->data == b) path2 = temp;
        
        if(root->left){
            temp.push_back('L');
            find(root->left,a,b,path1,path2,temp);
            temp.pop_back();
        }
        
        if(root->right){
            temp.push_back('R');
            find(root->right,a,b,path1,path2,temp);
            temp.pop_back();
        }
    }
   
    int findDist(Node* root, int a, int b) {
        // Your code here
        string path1 = "";
        string path2 = "";
        
        string temp = "L";
        find(root,a,b,path1,path2,temp);
        
        
        int i=0;
        
        while(i<path1.size() && i<path2.size() && path1[i] == path2[i]) i++;
        
        return path1.size()-i + path2.size()-i;
        
    }
};
