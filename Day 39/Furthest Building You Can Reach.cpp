/*

https://leetcode.com/problems/furthest-building-you-can-reach/description/

*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();

        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1; i<n; i++){
            int diff = heights[i] - heights[i-1];

            if(diff <= 0) continue;
            if(diff > 0) pq.push(diff);

            if(pq.size() > ladders){
                int num = pq.top();
                pq.pop();

                if(num <= bricks) bricks-=num;
                else return i-1;
            }
            
        }

        return n-1;
    }
};
