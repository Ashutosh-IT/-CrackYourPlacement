/*

https://www.geeksforgeeks.org/sort-a-linked-list-of-0s-1s-or-2s/

*/

#include<bits/stdc++.h>
using namespace std;

class Node 
{ 
  public:
    int data; 
    Node* next;
    
    Node(int x){
    	data = x;
    	next = NULL;
    }
}; 

Node *sort(Node *head){
	Node *zero = new Node(0);
	Node *one = new Node(1);
	Node *two = new Node(2);
	
	Node *tail0 = zero, *tail1 = one, *tail2 = two;
	
	Node *temp = head;
	while(temp){
		if(temp->data == 0){
			tail0->next = temp;
			temp = temp->next;
			tail0 = tail0->next;
			tail0->next = NULL;
		}
		else if(temp->data == 1){
			tail1->next = temp;
			temp = temp->next;
			tail1 = tail1->next;
			tail1->next = NULL;
		}
		else if(temp->data == 2){
			tail2->next = temp;
			temp = temp->next;
			tail2 = tail2->next;
			tail2->next = NULL;
		}
	}
	
	tail0->next = one->next;
	tail1->next = two->next;
	return zero->next;
}

int main(){
	int n;
	cin>>n;
	
	Node *head = new Node(0);
	Node *tail = head;
	
	for(int i=0; i<n; i++){
		int value;
		cin>>value;
		tail->next = new Node(value);
		tail = tail->next;
	}
	
	head = head->next;
	
	head = sort(head);
	Node *temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	
}
