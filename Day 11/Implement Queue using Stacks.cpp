/*

https://leetcode.com/problems/implement-queue-using-stacks/description/

*/

class MyQueue {
public:

    stack<int> st1;
    stack<int> st2;

    MyQueue() {}
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int num;
        if(!st2.empty()){
            num = st2.top();
            st2.pop();
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            num = st2.top();
            st2.pop();
        }

        return num;
    }
    
    int peek() {
        if(!st2.empty()) return st2.top();
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }

            return st2.top();
        }
    }
    
    bool empty() {
        if(st1.empty() && st2.empty())
        return true;

        return false;
    }
};
