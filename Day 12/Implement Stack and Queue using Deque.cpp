/*

https://www.geeksforgeeks.org/implement-stack-queue-using-deque/

*/


#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    
    deque<int> dq;
    
    Stack() {}
    
    void push(int x){
        dq.push_back(x);
    }
    
    void pop(){
        dq.pop_back();
    }
    
    int top(){
        return dq.back();
    }
    
    bool empty(){
        return dq.empty();
    }
    
    int size(){
        return dq.size();
    }
};

class Queue{
    public:
    deque<int> dq;
    
    Queue() {}
    
    void push(int x){
        dq.push_back(x);
    }
    
    void pop(){
        dq.pop_front();
    }
    
    int front(){
        return dq.front();
    }
    
    bool empty(){
        return dq.empty();
    }
    
    int size(){
        return dq.size();
    }
};


int main() {
    
    Stack st;
    
    st.push(6);
    st.push(7);
    cout<<st.empty()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    
    Queue q;
    q.push(5);
    q.push(6);
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    
    
}
