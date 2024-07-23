/*

https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

*/

class Solution
{
    public:
    
    Node *reverse(Node *head){
        if(!head) return NULL;
        
        Node *curr = head, *prev = NULL, *fut = NULL;
        
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        
        return prev;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        head = reverse(head);
        int maxi = head->data;
        
        Node *temp = head->next, *prev = head;
        
        while(temp){
            maxi = max(maxi,temp->data);
            if(temp->data < maxi){
                prev->next = temp->next;
                temp = temp->next;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        
        return reverse(head);
    }
    
};
