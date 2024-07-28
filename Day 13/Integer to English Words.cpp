/*

https://leetcode.com/problems/integer-to-english-words/

*/

class Solution {
public:

    string solve3digit(int n){

        if(n==0) return "";

        vector<string> units = {"One", "Two", "Three", "Four", "Five", "Six",   "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        vector<string> tens = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string ans = "";

        if(n/100 > 0){
            ans += units[n/100 - 1] + " Hundred";
            n %= 100;

            // abhi 2 digits aur baaki hai
            if(n>0){
                ans += " ";
            }
            else return ans;
        }

        // uska answer first array me milega
        if(n>=1 && n<=19){
            ans += units[n-1];
            return ans;
        }

        // vo 19 se bada hoga answer dusre array me milega
        else{
            ans += tens[n/10-2];
            n %= 10;

            //abhi last digit baaki h
            if(n){
                ans += " ";
                ans += units[n%10 - 1];
            }
        }

        return ans;
    }

    string numberToWords(int num) {
        
        if(num == 0) return "Zero";

        vector<string> hundreds = {"Thousand", "Million" , "Billion"};
        int count = -1;

        string ans = "";

        while(num){
            string curr = solve3digit(num%1000);

            if(!curr.empty()){
                if(!ans.empty()){
                    ans = curr + " " + (count >= 0 ? hundreds[count] + " " : "") + ans;
                }
                else{
                    ans = curr + (count >= 0 ? " " + hundreds[count] : "") + ans; 
                }
            }

            count++;
            num /= 1000;
        }

        return ans;
    }
};
