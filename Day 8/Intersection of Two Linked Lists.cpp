/*

https://leetcode.com/problems/intersection-of-two-linked-lists/description/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int count1 = 0, count2 = 0;
        ListNode *temp1 = headA, *temp2 = headB;

        while(temp1){
            count1++;
            temp1 = temp1->next;
        }

        while(temp2){
            count2++;
            temp2 = temp2->next;
        }

        temp1 = headA;
        temp2 = headB;

        if(count1 > count2){
            while(count1 != count2){
                count1--;
                temp1 = temp1->next;
            }
        }
        else{
            while(count2 != count1){
                count2--;
                temp2 = temp2->next;
            }
        }

        while(temp1 && temp2 && temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;
    }
};
