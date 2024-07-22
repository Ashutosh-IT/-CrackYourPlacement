/*

https://leetcode.com/problems/remove-linked-list-elements/description/

*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

       if(!head) return NULL;

       if(!head->next){
        if(head->val == val) return NULL;
        return head;
       }

       ListNode *curr = head, *prev = NULL;
       
       while(curr){
         if(curr->val == val){
            if(prev == NULL) head = curr->next;
            else prev->next = curr->next;
         }
         else prev = curr;
         curr = curr->next;
       }

       return head;

    }
};
