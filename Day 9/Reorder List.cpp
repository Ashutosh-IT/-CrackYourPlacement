/*

https://leetcode.com/problems/reorder-list/description/

*/

class Solution {
public:


    ListNode *reverse(ListNode* head){
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
    void reorderList(ListNode* head) {

        if(!head || !head->next) return;

        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = reverse(slow->next);
        slow->next = NULL;
        slow = head;
        while(fast){
            ListNode *temp = slow->next;
            slow->next = fast;
            fast = fast->next;
            slow->next->next = temp;
            slow = temp;
        }
        return;
    }
};
