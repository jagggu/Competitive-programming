/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
Each element of candidate is unique.
1 <= target <= 500


*/


class Solution {
public:
	
	void combinationSumHelper(vector<int> &nums, int start, int end, int target, vector<int> tmp, vector<vector<int> > &res) {
		/*
		if(start >= end) {
			return;
		}
		if(target < 0){
			return;
		}

		if(target == 0) {
			res.push_back(tmp);
			return;
		}

		tmp.push_back(nums[start]);
		combinationSumHelper(nums,start,end,target-nums[start],tmp,res);
		tmp.pop_back();
		combinationSumHelper(nums,start+1,end,target,tmp,res);
		*/

		if (target == 0) {
			res.push_back(tmp);
			return;
		}

		for (int i = start; i < end; i++) {
			if ((target - nums[i]) >= 0) {
				tmp.push_back(nums[i]);
				combinationSumHelper(nums, i, end, target - nums[i], tmp, res);
				tmp.pop_back();
			}
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		vector<vector<int> > res;
		vector<int> tmp;

		combinationSumHelper(candidates, 0, candidates.size(), target, tmp, res);

		return res;
	}
};