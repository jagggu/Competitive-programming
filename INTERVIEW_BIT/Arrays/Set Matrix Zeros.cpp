/*
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]


 */



void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if(A.size() < 1 || A[0].size() < 1) {
		return;
	}

	int rows = A.size();
	int cols = A[0].size();

	bool isRow = false;
	bool isCol = false;

	for(int i = 0;i<rows;i++) {
		for(int j = 0;j<cols;j++) {
			if(A[i][j] == 0) {
				
				if(i == 0) {
					isRow = true;
					continue;
				}

				if(j == 0) {
					isCol = true;
					continue;
				}

				A[0][j] = 0;
				A[i][0] = 0;
			}
		}
	}

	for(int i = 1;i < rows;i++) {
		for(int j = 1;j<cols; j++) {
			if(A[i][j] == 1) {
				if(A[i][0] == 0 || A[0][j] == 0) {
					A[i][j] = 0;
				}
			}
		}
	}

	if(A[0][0] == 0) {
		for(int i = 0;i<rows;i++) {
			A[i][0] = 0;
		}

		for(int i = 0;i<cols;i++) {
			A[0][i] = 0;
		}
	}

	if(isRow) {
		for(int i = 0;i<cols;i++) {
			A[0][i] = 0;
		}
	}

	if(isCol) {
		for(int i = 0;i<rows;i++) {
			A[i][0] = 0;
		}
	}
}
