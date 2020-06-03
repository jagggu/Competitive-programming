/*
Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

 Example: Input : 
    A : [1 3 5] 
    k : 4
 Output : YES as 5 - 1 = 4 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.

*/

int Solution::diffPossible(vector<int> &A, int B) {

    int n = A.size();
    if(n < 2) {
        return 0;
    }
    int start = 0;
    int end = 1;
    while(start < n && end<n) {
        int diff = A[end]-A[start];
        if(diff > B) {
            start++;
        } else if(diff < B) {
            end++;
        } else {
            if(start != end) {
            return 1;
            } else {
                end++;
            }
            
        }
    }
    return 0;
}
