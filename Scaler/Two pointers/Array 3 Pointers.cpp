/*

Array 3 Pointers
Problem Description
You are given 3 arrays A, B and C. All 3 of the arrays are sorted. Find i, j, k such that : max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized. Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])). abs(x) is absolute value of x and is implemented in the following manner : if (x < 0) return (-x)
else return (x)  


Problem Constraints
0 <= len(A),len(B),len(c) <= 106 0 <= A[i],B[i],C[i] <= 107 


Input Format
First argument is an integer array A. Second argument is an integer array B. Third argument is an integer array C. 


Output Format
Return an single integer denoting the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])).


Example Input
A = [1, 4, 10]
B = [2, 15, 20]
C = [10, 12]


Example Output
5


Example Explanation
With 10 from A, 15 from B and 10 from C.


*/


int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    int i = 0, j = 0,k = 0;
    int Alen = A.size();
    int Blen = B.size();
    int Clen = C.size();
    int ans = INT_MAX;
    while(i<Alen && j<Blen && k<Clen) {
        int maxEle = max(A[i],max(B[j],C[k]));
        int minEle = min(A[i],min(B[j],C[k]));
        
        ans = min(ans,abs(maxEle-minEle));
        
        if(A[i] == minEle) {
            i++;
        } else if(B[j] == minEle) {
            j++;
        } else {
            k++;
        }
    }
    return ans;
}
