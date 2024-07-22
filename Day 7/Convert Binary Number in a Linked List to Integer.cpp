/*

https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/

*/

class Solution {
public:
    
    ListNode *reverse(ListNode* head){
        if(!head) return head; 
        ListNode *curr = head, *prev = NULL, *fut = NULL;

        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }

        return prev;
    }
    int getDecimalValue(ListNode* head) {
        ListNode *temp = reverse(head);

        int ans = 0;
        int pow2 = 1;
        while(temp){
            if(temp->val) ans += pow2;
            pow2 *= 2;
            temp = temp->next;
        }

        return ans;
    }
};
