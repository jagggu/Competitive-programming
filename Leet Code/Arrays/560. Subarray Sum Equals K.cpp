/*

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].


*/



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       
        /*
        //Bruteforce approach
        int ans = 0;

        int n = nums.size();

        for(int i = 0;i<n;i++) {
        	int sum = 0;
        	for(int j = i;j<n;j++) {
        		sum += nums[j];
        		if(sum == k) {
        			ans++;
        		}
        	}
        }

        return ans;

        */


        unordered_map<int,int> m;
        m[0] = 1;

        

        int sum = 0;
        int ans = 0;
        for(int i = 0;i<nums.size(); i++) {

        	sum += nums[i];

        	ans += m[sum-k];

        	m[sum]++;
        }

        return ans;
    }
};