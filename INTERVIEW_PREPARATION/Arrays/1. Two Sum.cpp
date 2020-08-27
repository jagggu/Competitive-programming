/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  		unordered_map<int,int> m;
  		vector<int> res;
  		for(int i = 0;i<nums.size(); i++) {

  			int ele = target - nums[i];

  			if(m.find(ele) != m.end()) {
  				res.push_back(m[ele]);
  				res.push_back(i);

  				return res;
  			}

  			m[nums[i]] = i;
  		}

  		if(res.size() < 1) {
  			res.push_back(-1);
  			res.push_back(-1);
  		}

  		return res;      
    }


};