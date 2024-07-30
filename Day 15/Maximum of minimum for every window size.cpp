/*

https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

*/


class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        
        stack<int> st;
        vector<int> ans(n,0);

        for(int i=0; i<n; i++){
            
            if(st.empty()) 
            st.push(i);
            
            else if(arr[st.top()] <= arr[i])
            st.push(i);
            
            else{
                // we found our answer here
                int element = arr[st.top()];
                int right = i;
                
            
                st.pop();
                int left = st.empty() ? -1 : st.top();
                
                int size = right - left - 1;
                ans[size-1] = max(ans[size-1],element);
                
                i--;
            }
        }
        
        
        while(!st.empty()){
            int right = n;
            int element = arr[st.top()];
            st.pop();
            
            int left = st.empty() ? -1 : st.top();
                
            int size = right - left - 1;
            ans[size-1] = max(ans[size-1],element);
        }
        
        
        // fill the answer array
        for(int i=n-2; i>=0; i--){
            ans[i] = max(ans[i],ans[i+1]);
        }
        
        return ans;
        
        
    }
};
