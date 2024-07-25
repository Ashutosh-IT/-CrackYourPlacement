/*

https://leetcode.com/problems/merge-k-sorted-lists/description/

*/

class Solution {
public:

    ListNode* merge(ListNode *head1, ListNode *head2){
        if(!head1) return head2;
        if(!head2) return head1;

        ListNode *temp1 = head1, *temp2 = head2;
        ListNode *head = new ListNode(0);
        ListNode *tail = head;

        while(temp1 && temp2){

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


        if(temp1) tail->next = temp1;
        if(temp2) tail->next = temp2;

        return head->next;

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
         int n = lists.size();

         if(n==1) return lists[0];
         if(n==2) return merge(lists[0],lists[1]);

         ListNode *ans = NULL;

         for(int i=0; i<n; i++){
            ans = merge(ans,lists[i]);
         }

         return ans;

    }
};
