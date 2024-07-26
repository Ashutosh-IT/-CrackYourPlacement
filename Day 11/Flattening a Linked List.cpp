/*

https://www.geeksforgeeks.org/problems/flattening-a-linked-list--170645/1

*/

class Solution {
public:

    Node* merge(Node *head1, Node *head2){
        if(!head1) return head2;
        if(!head2) return head1;

        Node *temp1 = head1, *temp2 = head2;
        Node *head = new Node(0);
        Node *tail = head;

        while(temp1 && temp2){

            if(temp1->data < temp2->data){
                tail->bottom = temp1;
                temp1 = temp1->bottom;
            }
            else{
                tail->bottom = temp2;
                temp2 = temp2->bottom;
            }

            tail = tail->bottom;
            tail->bottom = NULL;
        }


        if(temp1) tail->bottom = temp1;
        if(temp2) tail->bottom = temp2;

        return head->bottom;

    }
    
    Node *flatten(Node *root)
    {
        // Your code here
        
        Node *ans = NULL, *temp = root;
        
        while(temp){
            ans = merge(ans,temp);
            temp = temp->next;
        }
        
        return ans;
    }
};
