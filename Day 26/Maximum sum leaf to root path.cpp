/*

https://www.geeksforgeeks.org/problems/maximum-sum-leaf-to-root-path/1

*/


class Solution{
    public:
    
    
    void find(Node* root, int &ans, int sum){
        if(!root) return;
        
        if(!root->left && !root->right){
            ans = max(ans,sum);
        }
        
        if(root->left){
            find(root->left,ans,sum+root->left->data);
        }
        
        if(root->right){
            find(root->right,ans,sum+root->right->data);
        }
        
    }
    
    int maxPathSum(Node* root)
    {
        //code here
        
        int sum = root->data;
        int ans = INT_MIN;
        
        find(root,ans,sum);
        
        return ans;
        
    }
};
