/*

https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;   
        ListNode *prev = head, *curr = head->next;

        while(curr){
            if(curr->val == prev->val){
                curr = curr->next;
            }
            else{
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        prev->next = NULL;
        return head;
    }
};
