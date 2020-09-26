/*

Find the closest pair from two sorted arrays
Given two sorted arrays of distinct integers, A and B, and an integer C, find and return the pair whose sum is closest to C and the pair has one element from each array. More formally, find A[i] and B[j] such that abs((A[i] + B[j]) - C) has minimum value. If there are multiple solutions find the one with minimum i and even if there are multiple values of j for the same i then return the one with minimum j. Note: Return an array with two elements {A[i], B[j]}. 
Input Format
The first argument given is the integer array A.
The second argument given is the integer array B.
The third argument given is integer C.
Output Format
Return the pair which has sum closest to C.
Constraints
1 <= length of both the arrays <= 100000
1 <= A[i], B[i] <= 10^9 
1 <= C <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = [2, 4, 6, 8]
    C = 9
Output 1:
    [1, 8]

Input 2:
    A = [5, 10, 20]
    B = [1, 2, 30]
    C = 13
Output 2:
    [10, 2]

*/



#define ll long long int

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {

  int ansStart = 100001;
  int ansEnd = 100001;

  int ALen = A.size();
  int BLen = B.size();

  int start = 0;
  int end  = BLen-1;
  ll ans = INT_MAX;

  while(start < ALen && end >=0) {

      ll tmp = abs(A[start] + B[end] - C);

      if(tmp < ans) {
        ansStart = start;
        ansEnd = end;
        
        ans = tmp;
        
      } else if(tmp == ans) {
          if(ansStart == start) {
              ansEnd = end;
          }
      }
      
      ll sum = A[start] + B[end];

      if(sum > C) {
        end--;
      } else {
        start++;
      }

  }

  vector<int> res;
  res.push_back(A[ansStart]);
  res.push_back(B[ansEnd]);
  return res;

}
