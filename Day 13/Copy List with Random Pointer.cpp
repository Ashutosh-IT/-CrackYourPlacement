/*

https://leetcode.com/problems/copy-list-with-random-pointer/description/

*/


// using map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*,Node*> mp;

        Node *temp = head;

        Node *head1 = NULL, *prev = NULL;

        while(temp){
            if(!prev){
                head1 = new Node(temp->val);
                mp[temp] = head1;
                prev = head1; 
            }
            else{
                Node *newNode = new Node(temp->val);
                prev->next = newNode;
                mp[temp] = newNode;
                prev = newNode;
            }
            temp = temp->next;
        }


        // create random pointer of all
        temp = head;
        Node *temp1 = head1;

        while(temp){
            if(temp->random == NULL){
                temp1->random = NULL;
            }
            else{
                temp1->random = mp[temp->random];
            }

            temp = temp->next;
            temp1 = temp1->next;
        }

        return head1;
    }
};



// Another approach without map
class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head) return NULL;
        
        Node *temp = head;

        // beech me Node add kro
        while(temp){
            Node *next = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = next;
            temp = next;
        }

        temp = head;

        // set random pointer
        while(temp){
            if(temp->random == NULL){
                temp->next->random = NULL;
            }
            else{
                temp->next->random = temp->random->next;
            }

            temp = temp->next->next;
        }


        temp = head;
        Node *head1 = head->next;

        // ab dono ko alag kro
        while(temp){
            Node *next = temp->next;
            temp->next = next->next;
            temp = temp->next;
            next->next = temp ? temp->next : NULL;
        }

        return head1;

    }
};
