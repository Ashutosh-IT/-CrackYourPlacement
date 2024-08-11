/*

https://www.geeksforgeeks.org/problems/largest-bst/1

*/

class Box{
public:
    bool BST;
    int min,max,size;
    
    Box(Node* root){
        BST = true;
        size = 1;
        min = max = root->data;
    }
};

class Solution{
    public:

     Box* find(Node* root, int &ans){
        // leaf node
        if(!root->left && !root->right){
            return new Box(root);
        }
        
        // only right part existd
        else if(!root->left){
            Box* right = find(root->right,ans);
            if(right->BST && right->min > root->data){
                right->min = root->data;
                right->size++;
                ans = max(ans,right->size);
                return right;
            }
            else{
                right->BST = false;
                return right;
            }
        }
        
        // only left part exists
        else if(!root->right){
            Box* left = find(root->left,ans);
            if(left->BST && left->max < root->data){
                left->max = root->data;
                left->size++;
                ans = max(ans,left->size);
                return left;
            }
            else{
                left->BST = false;
                return left;
            }
        }
        
        // if there are two childrens
        else{
            Box* left = find(root->left,ans);
            Box* right = find(root->right,ans);
            
            if(left->BST && right->BST && left->max < root->data && right->min > root->data){
                left->max = right->max;
                left->size += right->size+1;
                ans = max(ans,left->size);
                return left;
            }
            else{
                left->BST = false;
                return left;
            }
        }
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	int ans = 1;
    	find(root,ans);
    	return ans;
    }
};
