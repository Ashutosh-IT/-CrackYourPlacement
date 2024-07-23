/*

https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1

*/

class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        
        int mod = 1e9+7;
        
        long long num1 = 0;
        Node *temp1 = first;
        Node *temp2 = second;
        
        while(temp1){
            num1 = ((num1*10)%mod + (temp1->data%mod)) % mod;
            temp1 = temp1->next;
        }
        
        long long num2 = 0;
        while(temp2){
            num2 = ((num2*10)%mod + (temp2->data%mod)) % mod;
            temp2 = temp2->next;
        }
        
        return ((num1%mod) * (num2%mod)) % mod;
    }
};
