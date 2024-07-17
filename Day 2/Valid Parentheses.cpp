/*

https://leetcode.com/problems/valid-parentheses/

*/

class Solution {
public:
    bool isValid(string s) {

        int n = s.size();
        
        stack<int> st;

        for(int i=0; i<n; i++){

            if(st.empty()) st.push(s[i]);
            
            else if(st.top() == '(' && s[i] == ')') st.pop();
            else if(st.top() == '[' && s[i] == ']') st.pop();
            else if(st.top() == '{' && s[i] == '}') st.pop();
            else if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            
            else return false;
        }

        return st.empty();
    }
};
