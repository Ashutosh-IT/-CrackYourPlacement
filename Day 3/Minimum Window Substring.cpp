/*

https://leetcode.com/problems/minimum-window-substring/description/

*/

class Solution {
public:
    string minWindow(string s, string p) {
        unordered_map<char,int> mp;
        for(char ch : p) mp[ch]++;
        
        int i=0, j=0, count = p.size();
        int ans = INT_MAX, start = 0;
        
        while(j<s.size()){
            
            mp[s[j]]--;
            if(mp[s[j]] >= 0) count--;
            
            
            while(count == 0){
                if(ans > j-i+1){
                    ans = j-i+1;
                    start = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) count++;
                i++;
            }
            j++;
        }
        
        return ans == INT_MAX ? "" : s.substr(start,ans);
    }
};
