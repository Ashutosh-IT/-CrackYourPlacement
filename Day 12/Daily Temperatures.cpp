/*

https://leetcode.com/problems/daily-temperatures/description/

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        
        vector<int> ans(t.size(),0);
        stack<int> st;

        for(int i=0; i<t.size(); i++){

            if(st.empty())
            st.push(i);

            else if(t[st.top()] >= t[i])
            st.push(i);

            else{
                ans[st.top()] = i-st.top();
                st.pop();
                i--;
            }
        }

        return ans;
    }
};
