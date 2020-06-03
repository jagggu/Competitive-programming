/*
Smallest Prefix String
Problem Description
Given 2 strings A and B of size N and M respectively consisting of lowercase alphabets, find the lexicographically smallest string that can be formed by concatenating non empty prefixes of A and B (in that order). Note: The answer string has to start with a non empty prefix of string A followed by a non empty prefix of string B. 


Problem Constraints
1 <= N, M <= 100000


Input Format
First argument is a string A of size N.
Second argument is a string B of size M.


Output Format
Return a string denoting Lexicographically smallest string that can be formed by concatenating non empty prefixes of A and B (in that order).


Example Input
A = "abba"
B = "cdd"


Example Output
"abbac"


Example Explanation
We can concatenate prefixes of A i.e "abba" and prefixes of B i.e "c".
The lexicographically smallest string will be "abbac".

*/


string Solution::smallestPrefix(string A, string B) {

	string res;
	if(B.size() < 1) {
		return res;
	}
	for(int i = 0;i<A.size();i++) {
		if(res.size() < 1 || A[i] < B[0]) {
			res+=A[i];
		} else {
			res+=B[0];
			return res;
		}
	}
	res+=B[0];
	return res;

}
