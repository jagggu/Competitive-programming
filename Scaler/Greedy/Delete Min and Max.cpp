/*
Delete Min and Max
Problem Description

Given an array A, of N numbers, you want to keep only distinct numbers in the array.
To achieve this, you can pick any three numbers, and discard the maximum and minimum of the three, and keep the middle one back in the array.

Find the maximum number of distinct numbers in the array that will be left.



Problem Constraints
3 <= N <= 105
N is an odd number.
1 <= A[i] <= 105


Input Format
The first and the only argument of input contains an integer array A, of size N.



Output Format
Return an integer representing the answer.



Example Input
Input 1:

 A = [1, 1, 2]
Input 2:

 A = [1, 1, 2, 2, 2, 3, 1]


Example Output
Output 1:

 1
Output 2:

 3


Example Explanation
Explanation 1:

 You can pick 1, 1, 2. After discarding minimum (1) and maximum (2) from the array, you will have [1] left.
Explanation 2:

 You can pick 2, 2, 2. After discarding minimum (2) and maximum (2) from the array, you will have [1, 1, 2, 3, 1] left.
 You can pick 1, 1, 1. After discarding minimum (1) and maximum (1) from the array, you will have [1, 2, 3] left.

*/


int Solution::solve(vector<int> &A) {
	/*
	unordered_map<int,int> m;

	for(int ele : A) {
		m[ele]++;
	}

	int n = A.size();
	if(n<1) {
		return 0;
	}

	priority_queue<int> maxHeap;

	for(auto itr = m.begin(); itr != m.end(); itr++) {
		maxHeap.push(itr->second);
	}

	while(!maxHeap.empty()) {
		int top = maxHeap.top();

		if(top == 1) {
			break;
		}

		if(top == 2) {
			maxHeap.pop();
			//Only 2 same elements are present, So we can't pick the 3rd ele
			if(maxHeap.empty()) {
				break;
			}
			int top2 = maxHeap.top();
			maxHeap.pop();
			// Ex: 1 1 2 2. Each ele will present exactly once 
			if(top2 == 2) {
				maxHeap.push(1);
				maxHeap.push(1);
			} else {
				maxHeap.push(1);
			}
		} else {
			//Take 3 numbers out and remove 2 numbers and keep 1 number
			maxHeap.pop();
			maxHeap.push(top-3+1);
		}
	}

	return maxHeap.size();
	*/

	//Optimised Solution

	unordered_map<int,int> m;

	for(int ele : A) {
		m[ele]++;

		if(m[ele] > 2) {
			m[ele]-=2;
		}
	}

	int ans = 0;
	int twos = 0;

	for(auto itr : m) {
		if(itr.second > 0) {
			ans++;
		}

		if(itr.second == 2) {
			twos++;
		}
	}
	// If the the count of freq of eles having 2 are odd number then
	// number of unique elements will decrease by 1. Test with this example
	ans = ans - (twos&1);  // EX: 1 1 2 2 3 3
	return ans;
}
