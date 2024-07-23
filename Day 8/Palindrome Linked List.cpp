/*

https://leetcode.com/problems/palindrome-linked-list/description/

*/


class Solution {
public:


    ListNode* reverse(ListNode *root){
        if(!root || !root->next) return root;

        ListNode *curr = root, *prev = NULL, *fut = NULL;
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        if(!head->next) return true;

        ListNode *slow = head, *fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        } 

        fast = reverse(slow->next);
        slow = head;
        
        while(fast){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};
