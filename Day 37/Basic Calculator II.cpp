/*

https://leetcode.com/problems/basic-calculator-ii/

*/

class Solution {
public:
    int calculate(string s) {
        stack<pair<int,bool>> st;

        // solve divide first and multiply first
        int i=0;
        while(i<s.size()){

            // case 1 : space
            if(s[i] == ' '){
                i++;
                continue;
            }

            // case 2 : numbers
            if(s[i]>='0' && s[i]<='9'){
                string num = "";
                while(i<s.size() && (s[i]>='0' && s[i]<='9')){
                    num.push_back(s[i]);
                    i++;
                }
                int number = stoi(num);
                st.push({number,0});
            }
            

            // case 3 : + -
            else if(s[i]=='+' || s[i]=='-'){
                if(s[i]=='+') st.push({1,1});
                else st.push({2,1});
                i++;
            }
            

            // case 4 : * /
            else{
                bool mul = s[i] == '*';
                int num1 = st.top().first;
                st.pop();

                while(s[i]<'0' || s[i]>'9') i++;
                string num = "";
                while(i<s.size() && (s[i]>='0' && s[i]<='9')){
                    num.push_back(s[i]);
                    i++;
                }
                int num2 = stoi(num);
                int result = mul ? num1*num2 : num1/num2;
                st.push({result,0});
            }
        }

        // now solve addition and subtraction
        stack<pair<int,bool>> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }

        int ans = st2.top().first;
        st2.pop();
        while(!st2.empty()){
            int num1 = ans;
            bool add = st2.top().first == 1;
            st2.pop();
            int num2 = st2.top().first;
            st2.pop();

            ans = add ? num1 + num2 : num1 - num2;
        }

        return ans;
    }
};



