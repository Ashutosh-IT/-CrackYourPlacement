/*

https://leetcode.com/problems/next-greater-element-i/description/

*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        
        unordered_map<int,int> mp;

        for(int i=0; i<nums2.size(); i++){
            if(st.empty())
            st.push(i);

            else if(nums2[st.top()] >= nums2[i])
            st.push(i);

            else{
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
                i--;
            }
        }

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            if(mp.find(nums1[i]) == mp.end())
            ans.push_back(-1);
            else ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};
