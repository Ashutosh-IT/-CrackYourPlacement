/*

https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

*/

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int i=0;
        while(i<n){
            if(arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1]){
                
                int index = arr[i]-1;
                swap(arr[i],arr[index]);
                
            }
            else i++;
        }
    
        
        
        for(int j=0; j<n; j++){
            if(arr[j] != j+1)
            return j+1;
        }
        
        return n+1;
        
    } 
};



// Another Approach : Rohit negi - store two numbers in one place approach (negative waala)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]<=0) 
            nums[i] = n+1;
        }

        for(int i=0; i<n; i++){
            if(abs(nums[i])<=n)
            nums[abs(nums[i])-1] = nums[abs(nums[i])-1]<0 ? nums[abs(nums[i])-1] : -nums[abs(nums[i])-1];
        }

        for(int i=0; i<n; i++){
            if(nums[i]>0) return i+1;
        }

        return n+1;
    }
};
