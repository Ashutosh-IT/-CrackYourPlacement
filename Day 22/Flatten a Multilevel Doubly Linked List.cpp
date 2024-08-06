/*

https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        Node* temp = head;

        while(temp){

            if(temp->child){
                Node* next = temp->next;
                temp->next = temp->child;
                temp->child = NULL;
                temp->next->prev = temp;

                Node* temp1 = temp->next;
                while(temp1->next){
                    temp1 = temp1->next;
                }
                temp1->next = next;
                if(next) next->prev = temp1;
            }
            temp = temp->next;

        }

        return head;
    }
};
