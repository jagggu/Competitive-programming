/*
Gray Code
Problem Description
The gray code is a binary numeral system where two successive values differ in only one bit.
 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0. 


Problem Constraints
1 <= n <= 16


Input Format
First argument is an integer n.


Output Format
Return an array of integers representing the gray code sequence.


Example Input
Input 1:
2
 


Example Output
output 1:
[0,1,3,2]
 


Example Explanation
Explanation 1:
for n = 2 the gray code sequence is:
    00 - 0
    01 - 1
    11 - 3
    10 - 2
So, return [0,1,3,2].

*/



void grayCodeHelper(int n, vector<int> &res) {
    if(n == 1) {
        res.push_back(0);
        res.push_back(1);
        return;
    }
    grayCodeHelper(n-1,res);
    int size = res.size();
    for(int i = size-1;i>=0;i--) {
        res.push_back(res[i] | 1<<(n-1));
    }
}

vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> res;
    if(A < 1) {
        return res;
    }
    grayCodeHelper(A,res);
    return res;
}
