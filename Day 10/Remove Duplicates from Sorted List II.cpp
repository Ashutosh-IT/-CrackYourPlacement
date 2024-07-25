/*

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head || !head->next) return head; 
        ListNode *curr = head, *prev = NULL;

        while(curr && curr->next){
          
            if(curr->val == curr->next->val){
              
                int value = curr->val;
                while(curr && curr->val == value){
                    curr = curr->next;
                }
                if(!prev) head = curr;
                else prev->next = curr;
          
            }

            else{
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};
