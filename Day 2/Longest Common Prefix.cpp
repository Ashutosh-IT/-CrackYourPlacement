/*

https://leetcode.com/problems/longest-common-prefix/

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        sort(strs.begin(),strs.end());

        string one = strs[0];
        string two = strs.back();

        string ans = "";

        int i=0;
        int j=0;
        while(i<one.size() && j<two.size()){
            if(one[i] == two[j]){
                ans.push_back(one[i]);
                i++;
                j++;
            }
            else break;;
        }

        return ans;
    }
};
