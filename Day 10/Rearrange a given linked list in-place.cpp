/*

https://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/

*/

class Solution{ 
public:

    Node *reverse(Node* head){
        
        if(!head || !head->next) return head;
        Node *curr = head, *prev = NULL, *fut = NULL;

        while(curr){
            fut = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = fut;
        }

        return prev;
    }
    
    void reorderList(Node* head) {
        // Your code here
        if(!head || !head->next) return;

        Node *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = reverse(slow->next);
        slow->next = NULL;
        slow = head;
        while(fast){
            Node *temp = slow->next;
            slow->next = fast;
            fast = fast->next;
            slow->next->next = temp;
            slow = temp;
        }
        
        return;
    }
};

