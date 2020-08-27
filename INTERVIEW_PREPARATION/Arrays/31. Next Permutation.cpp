/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/



class Solution {
public:

	int findNextGreaterEle(vector<int> &nums, int ele, int index) {
		int n = nums.size();
		int currVal = INT_MAX;
		int currIndex = -1;

		for(int i = n-1;i>=index;i--) {
			if(nums[i] > ele) {
				return i;
			}
		}
        
        return -1;
	}

    void nextPermutation(vector<int>& nums) {
  		
  		int n = nums.size();
  		int ele = nums[n-1];
  		int index = n-2;

  		while(index >= 0) {
  			if(nums[index] < nums[index+1]) {
  				break;
  			}
  			index--;
  		}

  		if(index == -1) {
  			int left = 0;
  			int right = n-1;
  			while(left<=right) {
  				swap(nums[left],nums[right]);
  				left++;
  				right--;
  			}

  			return;
  		}      
            
       	int nextGreaterIndex = findNextGreaterEle(nums,nums[index],index+1);
        swap(nums[index], nums[nextGreaterIndex]);
  		sort(nums.begin()+index+1,nums.end());
  		
    }
};