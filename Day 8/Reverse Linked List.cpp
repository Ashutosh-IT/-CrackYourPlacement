/*

https://leetcode.com/problems/reverse-linked-list/

*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode *curr = head, *prev = NULL, *fut = NULL;

        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }

        return prev;
    }
};
