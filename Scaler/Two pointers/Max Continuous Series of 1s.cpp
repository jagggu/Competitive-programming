/*

Max Continuous Series of 1s
Problem Description
Given a binary array A, find the maximum sequence of continuous 1's that can be formed by replacing at-most B ones. For this problem, return the indices of maximum continuous series of 1s in order. If there are multiple possible solutions, return the sequence which has the minimum start index.  


Problem Constraints
0 <= M <= 105 1 <= size(A) <= 105 A[i]==0 or A[i]==1   


Input Format
First argument is an binary array A. Second argument is an integer B.  


Output Format
Return an array of integers denoting the indices(0-based) of 1's in the maximum continuous series.


Example Input
A = [1 1 0 1 1 0 0 1 1 1 ]
B = 1


Example Output
[0,1,2,3,4]


Example Explanation
Flipping 0 present at index 2 gives us the longest continous series of 1's i.e subarray [0:4].

*/


// At any point of time our window will have atmost B zeros
vector<int> Solution::maxone(vector<int> &A, int B) {
	int j = 0;
	int n = A.size();
	int start = 0;
	
	
	int maxWindow = 0;
	int zerosCount = 0;
	for(int i = 0;i<n;i++) {
		if(A[i] == 0) {
			zerosCount++;
		}
		while(zerosCount>B) {
			
			if(A[j] == 0) {
				zerosCount--;
			}

			j++;
		}
		//j++;
		if(maxWindow < (i-j+1)) {
			maxWindow = i-j+1;
			start = j;
		}
	}

	vector<int> ans;
	for(int k = 0; k<maxWindow;k++) {
		ans.push_back(start+k);
	}
	return ans;
}
