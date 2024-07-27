/*

https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

*/

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        
        stack<int> st;
        
        for(int i=0; i<S.size(); i++){
            
            if(S[i] >= '0' && S[i] <= '9')
            st.push(S[i]-'0');
            
            else{
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                
                if(S[i] == '+') st.push(num1+num2);
                if(S[i] == '-') st.push(num1-num2);
                if(S[i] == '*') st.push(num1*num2);
                if(S[i] == '/') st.push(num1/num2);
            }
        }
        
        return st.top();
    }
};
