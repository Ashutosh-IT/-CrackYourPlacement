/*

https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int s=1;
        int e=n-2;

        while(s <= e){
            int mid = s+(e-s)/2;

            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
            return mid;

            if(arr[mid] > arr[mid-1]) s=mid+1;
            else e=mid-1;
        }

        return -1;
    }
};
