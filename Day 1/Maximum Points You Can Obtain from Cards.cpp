/*

https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        if(k>n) return 0;

        int size = n-k;
        int sum = 0;
        int totalSum = 0;

        // 1st window sum
        for(int i=0; i<size; i++)
        sum += cardPoints[i];

        totalSum = sum;
        int ans = sum;

        int i=0, j=size;
        while(j<n){
            sum += cardPoints[j];
            sum -= cardPoints[i++];
            totalSum += cardPoints[j++];
            ans = min(ans,sum);
        }

        return totalSum - ans;
    }
};
