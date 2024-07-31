/*

https://leetcode.com/problems/lru-cache/description/

*/



class Node{
  public:
    int data;
    int key;
    Node *prev, *next;
    Node(int x, int y){
        data = x;
        key = y;
        prev = next = NULL;
    }
}; 


class LRUCache {
public:

    int size;
    int currSize;
    Node *head, *tail;

    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        size = capacity;
        currSize = 0;
        head = tail = NULL;
    }
    
    int get(int key) {

        // key doesn't exist
        if(mp.find(key) == mp.end())
        return -1;

        Node *curr = mp[key];

        // case 1 : head waale node ki hi value chahiye
        if(head == curr){

            // if only single element in list
            if(!head->next){
                return curr->data;
            }

            // multiple elements exists in list
            head = head->next;
        }
        // case 2 : tail waale node ki hi value chahiye
        else if(tail == curr){
            return tail->data;
        }

        // case 3 : middle element ki value chahiye
        else{
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        // add node in the last
        tail->next = curr;
        curr->prev = tail;
        curr->next = NULL;
        tail = tail->next;
        return curr->data;
    }
    
    void put(int key, int value) {

        // insert key
        if(mp.find(key) == mp.end()){
            
            // if the size is full
            if(currSize == size){ 

                // delete least recently used = (head)
                int k = head->key;  

                // if single element in list
                if(!head->next){
                    head = tail = NULL;
                    mp.erase(k);
                }

                // many elements are present
                else{
                    head = head->next;
                    mp.erase(k);
                }

                currSize--;
            }


            // now add new key : 2 cases

            // 1. list empty
            if(head == NULL){
                head = new Node(value,key);
                mp[key] = head;
                tail = head;
                currSize++;
                return;
            }

            // 2. list not empty
            tail->next = new Node(value,key);
            tail->next->prev = tail;
            mp[key] = tail->next;
            tail = tail->next;
            currSize++;
        }

        // update key
        else{

            Node *curr = mp[key];
            // case 1 : update karne waali key head to nhi hai
            if(head == curr){

                // if only one element in list
                if(!head->next){
                    head->data = value;
                    return;
                }

                // if multiple elements in list
                else{
                    head = head->next;
                }
            }

            // case 2 : update karne waali key tail to nhi hai
            else if(tail == curr){
                tail->data = value;
                return;
            }

            // case 3 : middle element to be updated
            else{
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }

            // add node in the last
            curr->data = value;
            tail->next = curr;
            curr->prev = tail;
            curr->next = NULL;
            tail = tail->next;
        }
    }
};
