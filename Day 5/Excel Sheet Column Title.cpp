/*

https://leetcode.com/problems/excel-sheet-column-title/description/

*/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans = "";

        while(columnNumber != 0){
            columnNumber--;
            int rem = columnNumber % 26;
            ans.push_back(rem+'A');
            columnNumber /= 26;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
