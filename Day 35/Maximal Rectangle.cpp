/*

https://leetcode.com/problems/maximal-rectangle/description/

*/


class Solution {
public:

    int maxRec(vector<int> &nums, int n){
        stack<int> st;
        int ans = 0;

        for(int i=0; i<n; i++){
            if(st.empty())
            st.push(i);

            else if(nums[st.top()] <= nums[i])
            st.push(i);

            else{
                int index = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                ans = max(ans,nums[index]*(i-left-1));
                i--;
            }
        }


        while(!st.empty()){
            int index = st.top();
            st.pop();
            int left = st.empty() ? -1 : st.top();
            ans = max(ans,nums[index]*(n-left-1));
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        vector<int> nums(m,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(matrix[i][j]=='1')
                nums[j]++;

                else nums[j] = 0;
            }
            ans = max(ans,maxRec(nums,m));
        }

        return ans;
    }
};
