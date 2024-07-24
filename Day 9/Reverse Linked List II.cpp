/*

https://leetcode.com/problems/reverse-linked-list-ii/description/

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

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode *temp = head;
        int count = 1;

        ListNode *first = NULL, *second = NULL, *third = NULL, *forth = NULL;

        while(temp){
            if(count == left-1){
                first = temp;
            }
            if(count == left){
                second = temp;
            }
            if(count == right){
                third = temp;
                forth = temp->next;
                break;
            }
            count++;
            temp = temp->next;
        }

        third->next = NULL;
        if(first != NULL)
        first->next = reverse(second);
        else{
            head = reverse(second);
        }
        second->next = forth;

        return head;
    }
};
