/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

*/


class Solution {
public:
	int findEle(vector<int> &nums, int target, int choice) {
		int start = 0;
		int end = nums.size()-1;
		int ans = -1;

		while(start <= end) {
			int mid = start + (end-start)/2;
			if(nums[mid] == target) {
				ans = mid;
				if(choice == 0) {
					end = mid-1;
				} else {
					start = mid+1;
				}
			} else if(target < nums[mid]) {
				end = mid-1;
			} else {
				start = mid+1;
			}
		}
		return ans;
	}
    vector<int> searchRange(vector<int>& nums, int target) {
  			
  			vector<int> res;
  			int firstPos = findEle(nums,target,0);
  			if(firstPos == -1) {
  				res.push_back(-1);
  				res.push_back(-1);
  				return res;
  			}		
  			int secondPos = findEle(nums,target,1);
  			res.push_back(firstPos);
  			res.push_back(secondPos);

  			return res;

    }
};