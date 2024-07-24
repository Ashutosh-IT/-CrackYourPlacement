/*

https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);

        ListNode *temp = head, *prev = NULL;

        if(n==1){
            head = head->next;
            return reverse(head);
        }

        n--;
        while(n--){
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        return reverse(head);
    }
};
