/*
Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.



Input Format

The first and only argument given is the integer matrix A.
Output Format

Return the overall median of the matrix A.
Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd
For Example

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2:
    17 ``` Matrix=

*/


int countLessNumbers(vector<vector<int> > &A, int ele) {
    int cnt = 0;
    for(int i = 0;i<A.size();i++) {
        cnt+=upper_bound(A[i].begin(),A[i].end(),ele)-A[i].begin();
    }
    return cnt;
}

int Solution::findMedian(vector<vector<int> > &A) {
    if(A.size() < 1 || A[0].size() < 1) {
        return 0;
    }
    
    int rows = A.size();
    int cols = A[0].size();
    
    int start = INT_MAX;
    int end = INT_MIN;
    
    for(int i = 0;i<rows;i++) {
        start = min(start,A[i][0]);
        end = max(end,A[i][cols-1]);
    }
    
    int n = rows*cols;
    int ans = 0;
    while(start <= end) {
        int mid = start + (end-start)/2;
        
        if(countLessNumbers(A,mid) <= n/2) {
            
            start = mid+1;
        } else {
            ans = mid;
            end = mid-1;
        }
    }
    
    return ans;
    
}
