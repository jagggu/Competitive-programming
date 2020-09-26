/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

*/



class Solution {
public:

	void combinationSum2Helper(vector<int> &nums, int start, int end, int target, vector<int> tmp, vector<vector<int> > &res) {

		if(target == 0) {
			res.push_back(tmp);
			return;
		}

		for(int i = start;i<end;i++) {
            if(i != start && nums[i] == nums[i-1]){
                continue;
            }
			if((target - nums[i]) >= 0) {
				tmp.push_back(nums[i]);
				combinationSum2Helper(nums,i+1,end,target-nums[i],tmp,res);
				tmp.pop_back();
			}
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  			
  			vector<vector<int> > res;
  			vector<int> tmp;
  			sort(candidates.begin(),candidates.end());
  			combinationSum2Helper(candidates,0,candidates.size(),target,tmp,res);

  			return res;      
    }
};