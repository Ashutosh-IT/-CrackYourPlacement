/*

https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

*/

#include <bits/stdc++.h> 
using namespace std; 

class Node{ 
  public: 
    int data; 
    Node *next; 
    
    Node(int x){
        data = x;
        next = NULL;
    }
}; 

Node *segregateEvenOdd(Node *head){
    
    Node *odd = new Node(0);
    Node *even = new Node(0);
    Node *tail1 = odd, *tail2 = even;
    
    Node *temp = head;
    while(temp){
        if(temp->data & 1){
            tail1->next = temp;
            temp = temp->next;
            tail1 = tail1->next;
            tail1->next = NULL;
        }
        else{
            tail2->next = temp;
            temp = temp->next;
            tail2 = tail2->next;
            tail2->next = NULL;
        }
    }
    
    tail2->next = odd->next;
    return even->next;
}

int main(){
    int n;
    cin>>n;
    
    Node *head = NULL, *tail = NULL;
    
    for(int i=0; i<n; i++){
        int value;
        cin>>value;
        if(!head){
            head = new Node(value);
            tail = head;
        }
        else{
            tail->next = new Node(value);
            tail = tail->next;
        }
    }
    
    
    head = segregateEvenOdd(head);
    Node *temp = head;
    
    while(temp){ 
        cout<<temp->data<<" "; 
        temp = temp->next; 
    } 
}
