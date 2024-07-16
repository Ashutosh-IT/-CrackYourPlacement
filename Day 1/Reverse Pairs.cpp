/*

https://leetcode.com/problems/reverse-pairs/description/

*/

class Solution {
public:
    int count = 0;


    void merge(vector<int> &nums, int s, int mid, int e){
        int size = e-s+1;
        vector<int> arr(size);
        int i=s, j=mid+1;
        int k=0;

        // reverse pair logic
        while(i<=mid && j<=e){
            while(j<=e && long(2)*nums[j] < nums[i]) j++;
            int c = j-(mid+1);
            count += c;
            i++;
        }

        if(i<=mid) count += (mid-i+1)*(j-(mid+1));

        // mergesort logic
        i=s, j=mid+1;

        while(i<=mid && j<=e){
            if(nums[i] < nums[j])
            arr[k++] = nums[i++];
            else
            arr[k++] = nums[j++];            
        }

        while(i<=mid) arr[k++] = nums[i++];
        while(j<=e) arr[k++] = nums[j++];

        for(int i=0; i<size; i++)
        nums[s++] = arr[i]; 
    }

    void mergesort(vector<int> &nums, int s, int e){
        if(s >= e) return;

        int mid = (s+e)/2;
        mergesort(nums,s,mid);
        mergesort(nums,mid+1,e);

        merge(nums,s,mid,e);
    }

    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return count;
    }
};
