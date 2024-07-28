/*

https://leetcode.com/problems/sum-of-subarray-minimums/description/

*/


// Brute force - O(n^2)
class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            int mini = INT_MAX;
            for(int j=i; j<n; j++){
                mini = min(mini,arr[j]);
                sum = (sum%mod + mini%mod)%mod;
            }
        }

        return sum;
    }
};



// Better Approach - O(N)
class Solution {
public:

    int mod = 1e9+7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n,n);
        vector<int> left(n,-1);

        stack<int> st;
        for(int i=0; i<n; i++){
            if(st.empty())
            st.push(i);

            else if(arr[st.top()] <= arr[i])
            st.push(i);

            else{
                right[st.top()] = i;
                st.pop();
                i--;
            }
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            if(st.empty())
            st.push(i);

            else if(arr[st.top()] < arr[i])
            st.push(i);

            else{
                left[st.top()] = i;
                st.pop();
                i++;
            }
        }


        long long sum = 0;
        for(int i=0; i<n; i++){
            long long ls = i-left[i];
            long long rs = right[i]-i;

            long long num = ls*rs;
            sum += (num*arr[i]);
        }

        return sum%mod;
    }
};

