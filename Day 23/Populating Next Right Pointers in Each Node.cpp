/*

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

*/

class Solution {
public:
    Node* connect(Node* root) {

        if(!root) return root;
        
        // leve; order traversal
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node *temp = q.front();
                q.pop();
                if(size == 0) temp->next = NULL;
                else temp->next = q.front();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }

        return root;

    }
};
