/*
Given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You should search for target in nums and if you found return its index, otherwise return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4

*/



class Solution {
public:
    int search(vector<int>& nums, int target) {
  		int n = nums.size();
  		int start = 0;
  		int end =  n-1;

  		while(start <= end) {
  			int mid = start + (end-start)/2;
            //cout<<start<<' '<<end<<' '<<mid<<endl;
  			if(nums[mid] == target) {
  				return mid;
  			}

  			if(nums[start] <= nums[mid]) { 

  				if(nums[start] <= target && target < nums[mid]) {
  					end = mid-1;
  				} else {
  					start = mid+1;
  				}
  			} else {
  				if(nums[mid] < target && target <= nums[end]) {
  					start = mid+1;
  				} else {
  					end = mid-1;
  				}
  			}
  		}

  		return -1;     
    }
};