/*

https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

*/

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        
        vector<int> mp(26,0);
        for(char ch : p) mp[ch-'a']++;
        
        int i=0, j=0, count = p.size();
        int ans = INT_MAX, start = 0;
        
        while(j<s.size()){
            
            mp[s[j]-'a']--;
            if(mp[s[j]-'a'] >= 0) count--;
            
            
            while(count == 0){
                if(ans > j-i+1){
                    ans = j-i+1;
                    start = i;
                }
                mp[s[i]-'a']++;
                if(mp[s[i]-'a'] > 0) count++;
                i++;
            }
            j++;
        }
        
        return ans == INT_MAX ? "-1" : s.substr(start,ans);
    }
};
