/*

https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/

*/

class Solution {
public:

    void merge(vector<pair<int,int>> &nums, int s, int mid, int e, vector<int> &ans){
        int size = e-s+1;
        vector<pair<int,int>> temp(size);
        int i=s;
        int j=mid+1;
        int k=0;

        while(i<=mid && j<=e){
            if(nums[i].first > nums[j].first){
                ans[nums[i].second] += e-j+1;
                temp[k] = nums[i];
                i++;
                k++;
            }
            else{
                temp[k] = nums[j];
                k++;
                j++;
            }
        }

        while(i<=mid){
            temp[k] = nums[i];
            i++;
            k++;
        }

        while(j<=e){
            temp[k] = nums[j];
            j++;
            k++;
        }

        for(int i=0; i<size; i++)
        nums[s++] = temp[i];
    }

    void mergeSort(vector<pair<int,int>> &nums, int s, int e, vector<int> &ans){
        if(s>=e) return;

        int mid = s+(e-s)/2;
        mergeSort(nums,s,mid,ans);
        mergeSort(nums,mid+1,e,ans);
        merge(nums,s,mid,e,ans);

    }

    vector<int> countSmaller(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int,int>> nums;
        for(int i=0; i<n; i++)
        nums.push_back({arr[i],i});

        vector<int> ans(n,0);
        mergeSort(nums,0,n-1,ans);
        return ans;

    }
};
