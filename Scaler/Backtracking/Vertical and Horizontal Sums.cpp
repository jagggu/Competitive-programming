/*

Given a matrix B, of size N x M, you are allowed to do at most A special operations on this grid such that there is no vertical or horizontal contiguous subarray that has a sum greater than C. A special operation involves multiplying any element by -1 i.e. changing its sign. Return 1 if it is possible to achieve the answer, otherwise 0. 
 Input Format:
The first argument is an integer A, representing the number of special operations allowed.
The second argument has the N x M integer matrix, B.
The third argument is an integer C, as described in the problem statement.
Output Format:
Return:
    => 1 : Answer exists
    => 0 : Answer does not exist
Constraints:
1 <= N, M <= 10
0 <= A <= 5
-1e5 <= B[i][j], C <= 1e5
Example: Input 1:
A = 3
B = [   [1, 1, 1]
        [1, 1, 1]
        [1, 1, 1]   ]
C = 2
Output 1:
1
Explanation 1:
The given matrix does not satisfy the conditions, but if we apply
the special operation to B[0][0], B[1][1], B[2][2], then the matrix would satisfy
the given conditions i.e. no row or column has a sum greater than 2.
Input 2:
A = 1
B = [   [1, 1, 1]
        [1, 1, 1]
        [1, 1, 1]   ]
C = 2
Output 2:
0
Explanation 2:
It is not possible to apply the special operation to 1 element
to satisfy the conditions.
 
 */ 

int kadensAlgo(vector<int> &arr) {
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    for(int i = 0;i<arr.size();i++) {
        maxEndingHere+=arr[i];
        if(maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
        }
        if(maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }
    return maxSoFar;
}

bool isValidCombo(vector<vector<int> > &arr, int sum) {
    for(int i = 0;i<arr.size();i++) {
        int tmpSum = kadensAlgo(arr[i]);
        if(tmpSum>sum) {
            return false;
        }
    }

    for(int j = 0;j<arr[0].size();j++) {
        vector<int> tmp;
        for(int i = 0;i<arr.size();i++) {
            tmp.push_back(arr[i][j]);
        }
        int tmpSum = kadensAlgo(tmp);
        if(tmpSum>sum) {
            return false;
        }
    }
    return true;
}

int solveHelper(vector<vector<int> > &arr, int attempts, int sum, int cols, int curr, int total) {
    
    if(attempts == 0) {
        return isValidCombo(arr,sum);
    }
    if(curr == total) {
        return isValidCombo(arr,sum);
    }
    int currRow = curr/cols;
    int currCol = curr%cols;
   // if(arr[currRow][currCol] > 0) { 
    arr[currRow][currCol] = -1*arr[currRow][currCol];
    int success = solveHelper(arr,attempts-1,sum,cols,curr+1,total);
    if(success) {
        return 1;
    }
    arr[currRow][currCol] = -1*arr[currRow][currCol];
    //return solveHelper(arr,attempts,sum,cols,curr+1,total);
   // }
    return solveHelper(arr,attempts,sum,cols,curr+1,total);


}

int Solution::solve(int A, vector<vector<int> > &B, int C) {

        if(B.size() < 1 || B[0].size() < 1) {
            return 0;
        }

        int cols = B[0].size();
        int rows = B.size();
        int total = rows*cols;
        return solveHelper(B,A,C,cols,0,total);
}
