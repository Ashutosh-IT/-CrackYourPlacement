/*

https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

*/


class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;

        for(int i=0; i<s.size(); i++){
            if(st.empty()) st.push({s[i],1});
            else{
                if(s[i] == st.top().first){
                    int freq = st.top().second;
                    st.pop();
                    if(freq+1 != k){
                        st.push({s[i],freq+1});
                    }
                }
                else{
                    st.push({s[i],1});
                }
            }
        }

        string ans = "";

        while(!st.empty()){
            int freq = st.top().second;
            char ch = st.top().first;
            st.pop();

            while(freq--) ans.push_back(ch); 
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
