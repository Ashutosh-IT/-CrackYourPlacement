/*

https://leetcode.com/problems/implement-stack-using-queues/description/

*/

class MyStack {
public:

    queue<int> q;
    int topp;
    MyStack() {
        topp = 0;
    }
    
    void push(int x) {
        q.push(x);
        topp = x;
    }
    
    int pop() {
        int size = q.size();
        while(size != 1){
            if(size == 2) topp = q.front();
            int num = q.front();
            q.pop();
            q.push(num);
            size--;
        }

        int num = q.front();
        q.pop();
        return num;
    }
    
    int top() {
        return topp;
    }
    
    bool empty() {
        return q.empty();
    }
};
