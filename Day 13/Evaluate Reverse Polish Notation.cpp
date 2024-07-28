/*

https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

*/

class Solution {
public:

    int stoi(string num){
        bool negative = false;
        if(num[0] == '-') negative = true;

        int i = negative ? 1 : 0;

        int ans = 0;
        while(i<num.size()){
            ans = ans*10 + (num[i]-'0');
            i++;
        }

        return negative ? -ans : ans;
    }

    int evalRPN(vector<string>& tokens) {

        int n = tokens.size();
        stack<int> st;

        for(int i=0; i<n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if(tokens[i] == "+") st.push(num1 + num2);
                if(tokens[i] == "-") st.push(num1 - num2);
                if(tokens[i] == "*") st.push(num1 * num2);
                if(tokens[i] == "/") st.push(num1 / num2);
            }
            else st.push(stoi(tokens[i]));
        }

        return st.top();
    }
};
