/*

https://leetcode.com/problems/reverse-nodes-in-k-group/description/

*/

class Solution {
public:

    ListNode* reverse(ListNode* head){

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


    ListNode* reverseKGroup(ListNode* head, int k) {

        if(k==1) return head;
        
        int count = 1;
        ListNode *first = NULL, *second = head, *third = NULL, *forth = NULL;

        ListNode *temp = head;

        while(temp){

            while(temp && count != k){
                if(temp->next) count++;
                temp = temp->next;
            }

            if(count == k){
                third = temp;
                forth = temp->next;

                third->next = NULL;
                
                if(!first) head = reverse(head);
                else first->next = reverse(second);

                first = second;
                second = forth;
                count = 1;
                temp = second;
            }

            else{
                first->next = second;
            }
        }

        return head;


        
    }
};
