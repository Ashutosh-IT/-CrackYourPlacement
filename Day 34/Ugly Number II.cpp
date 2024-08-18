/*

https://leetcode.com/problems/ugly-number-ii/description/

*/

class Solution {
public:
    int nthUglyNumber(int n) {
        long long num;
        num = 1;

        set<long long> st;
        int count = 1;

        while(count != n){

            long long prev = num;
            st.insert(prev*2);
            st.insert(prev*3);
            st.insert(prev*5);

            long long nextNum = *st.begin();
            num = nextNum;
            count++;
            st.erase(nextNum); 

        }

        return num;
    }
};
