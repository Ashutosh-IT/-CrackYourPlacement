/*

https://www.geeksforgeeks.org/problems/minimum-swaps/1

*/

class Solution 
{
  public:
  //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>> v;
	    for(int i=0; i<nums.size(); i++)
	    v.push_back({nums[i],i});
	    
	    sort(v.begin(),v.end());
	    int swaps = 0;
	    
	    int i=0;
	    while(i<nums.size()){
	        if(v[i].second == i) i++;
	        else{
	            swap(v[i],v[v[i].second]);
	            swaps++;
	        }
	    }
	    
	    return swaps;
	}
};
