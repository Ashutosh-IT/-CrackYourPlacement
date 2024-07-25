/*

https://www.geeksforgeeks.org/problems/linked-list-in-zig-zag-fashion/1

*/

class Solution {
  public:
    Node* zigZag(Node* head) {
        // your code goes here
        
        if(!head->next) return head;
    
        Node *curr = head;
        bool flag = true;
        
        while(curr->next){
            
            if(flag){
                if(curr->next->data < curr->data)
                swap(curr->next->data,curr->data);
            }
            else{
                if(curr->next->data > curr->data)
                swap(curr->next->data,curr->data);
            }
            
            curr = curr->next;
            flag = !flag;
        }
        
        return head;
    }
};
