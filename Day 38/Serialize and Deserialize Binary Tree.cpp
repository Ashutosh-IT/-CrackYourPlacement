/*

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string ans = "";
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(!temp){
                ans = ans + "N ";
                continue;
            }
            int data = temp->val;
            if(data < 0) ans.push_back('-');
            string s = to_string(abs(data));
            ans = ans + s + " ";

            q.push(temp->left);
            q.push(temp->right);
        }

        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        cout<<data;

        int n = data.size();
        if(n == 0) return NULL;
        int i=0;
        bool neg = data[0] == '-';
        if(neg) i++;

        string num = "";
        while(i<n && data[i] != ' '){
            num.push_back(data[i]);
            i++;
        }

        int number = stoi(num);
        if(neg) number *= -1;

        TreeNode* root = new TreeNode(number);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            i++;
            neg = data[i] == '-';
            if(neg) i++;
            
            if(data[i] == 'N'){
                temp->left = NULL;
                i++;
            }
            else{
                num = "";
                while(i<n && data[i] != ' '){
                    num.push_back(data[i]);
                    i++;
                }

                number = stoi(num);
                if(neg) number *= -1;


                temp->left = new TreeNode(number);
                q.push(temp->left);
            }

            i++;
            neg = data[i] == '-';
            if(neg) i++;
            
            if(data[i] == 'N'){
                temp->right = NULL;
                i++;
            }
            else{
                num = "";
                while(i<n && data[i] != ' '){
                    num.push_back(data[i]);
                    i++;
                }

                number = stoi(num);
                if(neg) number *= -1;


                temp->right = new TreeNode(number);
                q.push(temp->right);
            }
            
        }

        return root;
    }
};
