/*

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/



class Solution {
public:

	void subsetsHelper(vector<int> &nums, int start, int end, vector<int> tmp, vector<vector<int> > &res) {
		res.push_back(tmp);

		for(int index = start; index < end; index++) {
			tmp.push_back(nums[index]);
			subsetsHelper(nums,index+1,end,tmp,res);
			tmp.pop_back();
		}
	}

    vector<vector<int>> subsets(vector<int>& nums) {
  		
  		vector<vector<int> > res;
  		vector<int> tmp;

  		subsetsHelper(nums,0,nums.size(),tmp,res);

  		return res;      
    }
};