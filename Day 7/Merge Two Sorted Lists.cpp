/*

https://leetcode.com/problems/merge-two-sorted-lists/description/

*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode *temp1 = list1, *temp2 = list2;

        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode *head = NULL, *tail = NULL;

        while(temp1 && temp2){
            if(head == NULL){
                if(temp1->val < temp2->val){
                    head = temp1;
                    temp1 = temp1->next;
                }
                else{
                    head = temp2;
                    temp2 = temp2->next;
                }
                tail = head;
            }
            else{
                if(temp1->val < temp2->val){
                    tail->next = temp1;
                    temp1 = temp1->next;
                }
                else{
                    tail->next = temp2;
                    temp2 = temp2->next;
                }
                tail = tail->next;
            }
        }

        while(temp1){
            tail->next = temp1;
            temp1 = temp1->next;
            tail = tail->next;
        }

        while(temp2){
            tail->next = temp2;
            temp2 = temp2->next;
            tail = tail->next;
        }

        return head;
    }
};
