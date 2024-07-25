/*

https://leetcode.com/problems/sort-list/description/

*/

class Solution {
public:

    ListNode* merge(ListNode* left, ListNode* right){
        if(!left) return right;
        if(!right) return left;

        ListNode *head = NULL, *tail = NULL;
        ListNode *temp1 = left, *temp2 = right;

        while(temp1 && temp2){

            if(!head){
                if(temp1->val < temp2->val){
                    head = temp1;
                    temp1 = temp1->next;
                }
                else{
                    head =temp2;
                    temp2 = temp2->next;
                }
                tail = head;
                tail->next = NULL;
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
                tail->next = NULL;   
            }
        }

        if(temp1) tail->next = temp1;
        if(temp2) tail->next = temp2;

        return head;
    }

    ListNode* findMid(ListNode* head){
        ListNode *slow = head, *fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeSort(ListNode *head){
        if(!head || !head->next) return head;

        ListNode* mid = findMid(head);
        ListNode *left = head, *right = mid->next;
        mid->next = NULL;

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left,right);
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        head = mergeSort(head);
        return head;
    }
};
