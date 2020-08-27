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
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9

*/


class Solution {
public:

	int searchElement(vector<int> &nums, int target, string toFind) {
		int ans = -1;

		int start = 0;
		int end = nums.size()-1;

		while(start <= end) {
			int mid = start + (end-start)/2;

			if(nums[mid] == target) {
				ans = mid;
				if(toFind == "lower") {
					end = mid-1;
				} else {
					start = mid+1;
				}
			} else if(nums[mid] < target) {
				start = mid+1;
			} else {
				end = mid-1;
			}
		}

		return ans;
	}

    vector<int> searchRange(vector<int>& nums, int target) {
  		
  		vector<int> res(2);

  		int lowerIndex = searchElement(nums,target,"lower");
  		if(lowerIndex == -1) {
  			res[0] = -1;
  			res[1] = -1;
  			return res;
  		}      

  		int upperIndex = searchElement(nums,target, "upper");

  		res[0] = lowerIndex;
  		res[1] = upperIndex;

  		return res;
    }
};