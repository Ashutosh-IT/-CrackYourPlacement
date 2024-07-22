/*

https://leetcode.com/problems/middle-of-the-linked-list/description/

*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
