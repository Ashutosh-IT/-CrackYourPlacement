/*

https://leetcode.com/problems/add-two-numbers-ii/description/

*/

class Solution {
public:

    ListNode *reverse(ListNode* head){
        if(!head) return NULL;

        ListNode *curr = head, *prev = NULL, *fut = NULL;

        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = reverse(l1), *temp2 = reverse(l2);

        ListNode *head = new ListNode(0);
        ListNode *tail = head;

        int carry = 0;

        while(temp1 && temp2){
            int sum = temp1->val + temp2->val + carry;
            if(sum >= 10){
                carry = 1;
                sum %= 10; 
            }
            else{
                carry = 0;
            }
            tail->next = new ListNode(sum);
            tail = tail->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1){
            int sum = temp1->val + carry;
            if(sum >= 10){
                sum %= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            tail->next = new ListNode(sum);
            tail = tail->next;
            temp1 = temp1->next;
        }

        while(temp2){
            int sum = temp2->val + carry;
            if(sum >= 10){
                sum %= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            tail->next = new ListNode(sum);
            tail = tail->next;
            temp2 = temp2->next;
        }

        if(carry) tail->next = new ListNode(1);

        head = head->next;
        return reverse(head); 
    }
};
