/*

https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

*/

class twoStacks {
  public:
    
    int arr[200];
    int top1;
    int top2;
    
    twoStacks() {
        top1 = -1;
        top2 = 200;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        top1++;
        arr[top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        top2--;
        arr[top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(top1 == -1) return -1;
        int num = arr[top1];
        top1--;
        return num;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 == 200) return -1;
        int num = arr[top2];
        top2++;
        return num;
    }
};
