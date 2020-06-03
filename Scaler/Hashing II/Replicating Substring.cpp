/*
Replicating Substring
Problem Description
Given a string B, find if it is possible to re-order the characters of the string B so that it can be represented as a concatenation of A similar strings. Eg: B = aabb and A = 2, then it is possible to re-arrange the string as "abab" which is a concatenation of 2 similar strings "ab". If it is possible, return 1, else return -1. 


Problem Constraints
1 <= Length of string B <= 1000
All the alphabets of S are lower case (a - z)
1 <= A <= 1000


Input Format
First argument is an integer A.
Second argument is a string B.


Output Format
Your function should return 1 if it is possible to re-arrange the characters of the string B so that it can be represented as a concatenation of A similar strings. If it is not, return -1.


Example Input
A = 2
B = "bbaabb"


Example Output
1


Example Explanation
We can re-order the given string into "abbabb".

*/


int Solution::solve(int A, string B) {
	
	unordered_map<char,int> m;

	for(auto ele : B) {
		m[ele]++;
	}    

	for(auto itr = m.begin(); itr != m.end(); itr++) {
		if(itr->second%A != 0) {
			return -1;
		}
	}
	return 1;
}
