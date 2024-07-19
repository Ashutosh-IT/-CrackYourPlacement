/*

https://www.geeksforgeeks.org/problems/max-rectangle/1

*/

class Solution{
  public:
  
    int find(vector<int> &row, int n){

        stack<int> st;
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            
            if(st.empty()) st.push(i);
            
            else if(row[st.top()] <= row[i]) st.push(i);
            
            else{
                int right = i;
                int height = row[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                ans = max(ans,(right-left-1)*height);
                i--;
            }
            
        }
        
        while(!st.empty()){
            int right = n;
            int height = row[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            ans = max(ans,(right-left-1)*height);
        }
        
        return ans;
        
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        vector<int> row(m,0);
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
            row[j] = M[i][j] ? row[j]+1 : 0;
            ans = max(ans,find(row,m));
        }
        
        return ans;
    }
};
