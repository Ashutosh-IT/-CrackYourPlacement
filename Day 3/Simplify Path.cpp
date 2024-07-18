/*

https://leetcode.com/problems/simplify-path/description/

*/

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();

        stack<string> st;

        int i=0;
        while(i<n){
            if(path[i] == '/') i++;
            else{
                string temp = "";
                while(i<n && path[i] != '/')
                temp.push_back(path[i++]);

                if(temp == ".."){
                    if(!st.empty()) st.pop();
                }
                else if(temp == "."){
                    continue;
                }
                else st.push(temp);
            }
        }

        stack<string> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }

        string ans = "";

        while(!st2.empty()){
            ans.push_back('/');
            ans += st2.top();
            st2.pop();
        }

        return ans.size() ? ans : "/";

    }
};
