/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		vector<vector<int> > res;

		sort(nums.begin(), nums.end());

		int n = nums.size();

		for (int i = 0; i < n - 2; i++) {

			if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {

				int lo = i + 1;
				int hi = n - 1;

				int target = -1 * nums[i];

				while (lo < hi) {
                    //cout<<lo<<' '<<hi<<endl;
					if ((nums[lo] + nums[hi]) == target) {
						vector<int> tmp(3);
						tmp[0] = nums[i];
						tmp[1] = nums[lo];
						tmp[2] = nums[hi];
						res.push_back(tmp);

						while ((lo < hi) && nums[lo] == nums[lo + 1]) {
							lo++;
						}

						while ((lo < hi) && nums[hi] == nums[hi - 1]) {
							hi--;
						}

						lo++;
						hi--;
					} else if ((nums[lo] + nums[hi]) < target) {
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