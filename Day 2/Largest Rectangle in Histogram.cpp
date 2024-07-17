/*

https://leetcode.com/problems/largest-rectangle-in-histogram/

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        
        int ans = 0;
        stack<int> st;

        for(int i=0; i<n; i++){

            if(st.empty())
            st.push(i);

            else if(heights[st.top()] <= heights[i]){
                st.push(i);
            }

            else{
                int right = i;
                int h = heights[st.top()];
                st.pop();
                i--;
                int left = st.empty() ? -1 : st.top();
                ans = max(ans,(right-left-1)*h);
            }
        }

        while(!st.empty()){
            int right = n;
            int h = heights[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            ans = max(ans,(right-left-1)*h);
        }
        
        return ans;
    }
};
