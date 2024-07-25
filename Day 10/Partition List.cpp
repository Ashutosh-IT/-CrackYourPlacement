/*

https://leetcode.com/problems/partition-list/description/

*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        if(!head || !head->next) return head;
        
        ListNode *small = NULL, *Stail = NULL;
        ListNode *large = NULL, *Ltail = NULL;

        ListNode *temp = head;

        while(temp){
            if(temp->val < x){
                if(!small){
                    small = temp;
                    Stail = temp;
                    temp = temp->next;
                    Stail->next = NULL;
                }
                else{
                    Stail->next = temp;
                    temp = temp->next;
                    Stail = Stail->next;
                    Stail->next = NULL;
                }
            }
            else{
                if(!large){
                    large = temp;
                    Ltail = temp;
                    temp = temp->next;
                    Ltail->next = NULL;
                }
                else{
                    Ltail->next = temp;
                    temp = temp->next;
                    Ltail = Ltail->next;
                    Ltail->next = NULL;
                }
            }
        } 

        if(!Stail) return large;
        
        Stail->next = large;
        return small;
    }
};
