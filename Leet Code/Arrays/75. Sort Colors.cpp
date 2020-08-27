class Solution {
public:
    void sortColors(vector<int>& nums) {
  		
  		int n = nums.size();
  		int index = 0;
  		int zerosIndex = 0;
  		int twosIndex = nums.size() - 1;

  		while(index < n && twosIndex >= 0) {
  			if(nums[index] == 2) {
  				nums[index] = nums[twosIndex];
  				nums[twosIndex] = 2;
  				twosIndex--;
  			} else if(nums[index] == 0) {
  				nums[index] = nums[zerosIndex];
  				nums[zerosIndex] = 0;
  				zerosIndex++;
  				index++;
  			} else {
  				index++;
  			}
  		}      
    }
};