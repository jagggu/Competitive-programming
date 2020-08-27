/*
Min Sum Path in Triangle
Problem Description

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

Adjacent numbers for jth number of row i is jth and (j+1)th numbers of row i+1 is



Problem Constraints
|A| <= 1000

A[i] <= 1000



Input Format
First and only argument is the vector of vector A defining the given triangle



Output Format
Return the minimum sum



Example Input
Input 1:

 
A = [ 
         [2],
        [3, 4],
       [6, 5, 7],
      [4, 1, 8, 3]
    ]
Input 2:

 A = [ [1] ]


Example Output
Output 1:

 11
Output 2:

 1


Example Explanation
Explanation 1:

 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Explanation 2:

 Only 2 can be collected.

*/



bool isOutOfMatrix(int i, int j, int rows, int cols) {
	return i<j || i>=rows;
}

int minSumTotalHelper(vector<vector<int> > &A, int i, int j, int rows, int cols, vector<vector<int> > &minSum) {

	if(isOutOfMatrix(i,j,rows,cols)) {
		return 0;
	}
   // cout<<"checkPoint"<<endl;
	if(minSum[i][j] != -1) {
		return minSum[i][j];
	}

	int ans = min(minSumTotalHelper(A,i+1,j,rows,cols,minSum),minSumTotalHelper(A,i+1,j+1,rows,cols,minSum)) + A[i][j];
	
//	cout<<i<<' '<<j<<' '<<ans<<endl;

	return minSum[i][j] = ans;
}

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int rows = A.size();
	int cols = A[0].size();

	vector<vector<int> > minSum;
	vector<int> tmp;
	for(int i = 0;i<rows;i++) {
		tmp.clear();
		for(int j = 0;j<=i;j++) {
			tmp.push_back(-1);
		}
		minSum.push_back(tmp);
	}

	minSumTotalHelper(A,0,0,rows,cols,minSum);

	int ans = INT_MAX;
	for(int ele : minSum[rows-1]) {
	    if(ele != -1) {
		ans = min(ans,ele);
	    }
	}

	return minSum[0][0];
}
