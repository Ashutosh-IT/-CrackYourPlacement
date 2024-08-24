/*

https://leetcode.com/problems/decode-ways/

*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        if(s[0] == '0') return 0;

        int dp[n];
        dp[0] = 1;
        if(n>1) dp[1] = stoi(s.substr(0,2)) <= 26 ? (s[1] != '0' ? 2 : 1) : (s[1] == '0' ? 0 : 1);

        for(int i=2; i<n; i++){
            dp[i] = s[i] == '0' ? 0 : dp[i-1];
            if(stoi(s.substr(i-1,2)) <= 26 && s[i-1] != '0')
            dp[i] += dp[i-2];
        }

        return dp[n-1];
    }
};
