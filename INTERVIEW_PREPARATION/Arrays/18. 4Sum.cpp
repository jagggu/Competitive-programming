/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
  		
  		vector<vector<int> > res;

  		int n = nums.size();

  		sort(nums.begin(),nums.end());

  		for(int i = 0;i<n-3;i++) {

  			if(i != 0 && nums[i] == nums[i-1]) {
  				continue;
  			}


  			for(int j = i+1;j<n-2;j++) {

  				if(j != (i+1) && nums[j] == nums[j-1]) {
  					continue;
  				}

  				int lo = j+1;
  				int hi = n-1;
  				int eleToFind = target - nums[i] - nums[j];

  				while(lo < hi) {
  					if(nums[lo] + nums[hi] == eleToFind) {
  						vector<int> tmp(4);
  						tmp[0] = nums[i];
  						tmp[1] = nums[j];
  						tmp[2] = nums[lo];
  						tmp[3] = nums[hi];
  						res.push_back(tmp);

  						while(lo<hi && nums[lo] == nums[lo+1]) {
  							lo++;
  						}

  						while(lo<hi && nums[hi] == nums[hi-1]) {
  							hi--;
  						}

  						lo++;
  						hi--;
  					} else if((nums[lo] + nums[hi]) < eleToFind) {
  						lo++;
  					} else {
  						hi--;
  					}
  				}
  			}
  		}

  		return res;      
    }
};