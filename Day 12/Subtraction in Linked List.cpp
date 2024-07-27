/*

https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1

*/

class Solution {
public:

    Node *reverse(Node *head){
        
        if(!head) return head;
        Node *curr = head, *prev = NULL, *fut = NULL;
        
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        
        return prev;
        
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        
        Node *temp1 = head1, *temp2 = head2;
        
        while(temp1 && temp1->data == 0) temp1 = temp1->next;
        while(temp2 && temp2->data == 0) temp2 = temp2->next;
        
        
        if(!temp1 && !temp2) return new Node(0);
        if(!temp1) return temp2;
        if(!temp2) return temp1;
        
        int count1 = 0, count2 = 0;
        
        Node *first = temp1, *second = temp2;
        
        while(first){
            count1++;
            first = first->next;
        }
        
        while(second){
            count2++;
            second = second->next;
        }
        
        if(count1 > count2){
            first = temp1;
            second = temp2;
        }
        else if(count1 < count2){
            first = temp2;
            second = temp1;
        }
        else{
            while(temp1 && temp1->data == temp2->data){
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            
            if(!temp1) return new Node(0);
            if(temp1->data > temp2->data){
                first = temp1;
                second = temp2;
            }
            else{
                first = temp2;
                second = temp1;
            }
        }
        
        first = reverse(first);
        second = reverse(second);
        
        Node *ans = new Node(0);
        Node *tail = ans;
        
        
        int carry = 0;
        
        while(first && second){
            
            if(carry == 0){
                
                if(first->data >= second->data){
                    int diff = first->data - second->data;
                    tail->next = new Node(diff); 
                }
                else{
                    carry = 1;
                    int diff = first->data + 10 - second->data;
                    tail->next = new Node(diff);
                }
                
                tail = tail->next;
                first = first->next;
                second = second->next;
            }
            
            else{
                
                if(first->data != 0){
                    first->data = first->data - 1;
                    carry = 0;
                }
                else{
                    tail->next = new Node(9-second->data);
                    tail = tail->next;
                    first = first->next;
                    second = second->next;
                }
            }
            
            
        }
        
        while(first){
            if(carry){
                if(first->data != 0){
                    tail->next = new Node(first->data - 1);
                    carry = 0;
                }
                
                else{
                    tail->next = new Node(9);
                }
            }
            else{
                tail->next = new Node(first->data);
            }
            
            first = first->next;
            tail = tail->next;
        }
        
        while(second){
            if(carry){
                if(second->data != 0){
                    tail->next = new Node(second->data - 1);
                    carry = 0;
                }
                
                else{
                    tail->next = new Node(9);
                }
            }
            else{
                tail->next = new Node(second->data);
            }
            tail = tail->next;
            second = second->next;
        }
        
        ans = ans->next;
        ans = reverse(ans);
        
        while(ans && ans->data == 0){
            ans = ans->next;
        }
        
        if(!ans) return new Node(0);
        
        return ans;
        
    }
};
