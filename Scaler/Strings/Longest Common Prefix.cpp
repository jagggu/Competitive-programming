/*
Longest Common Prefix
Problem Description
Given the array of strings A, you need to find the longest string S which is the prefix of ALL the strings in the array. Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2. For Example: longest common prefix of "abcdefgh" and "abcefgh" is "abc".  


Problem Constraints
0 <= sum of length of all strings <= 1000000


Input Format
The only argument given is an array of strings A.


Output Format
Return the longest common prefix of all strings in A.


Example Input
Input 1:
A = ["abcdefgh", "aefghijk", "abcefgh"]
Input 2:
A = ["abab", "ab", "abcd"];
 


Example Output
Output 1:
"a"
Output 2:
"ab"
 


Example Explanation
Explanation 1:
Longest common prefix of all the strings is "a".
Explanation 2:
Longest common prefix of all the strings is "ab".

*/


string findPrefix(string str1, string str2) {
	int i = 0,j=0;
	int str1Len = str1.length();
	int str2Len = str2.length();
	string tmp;
	while(i<str1Len && j<str2Len) {
		if(str1[i] != str2[j]) {
			return tmp;
		}
		tmp.push_back(str1[i]);
	}
	return tmp;
}

string Solution::longestCommonPrefix(vector<string> &A) {

	string res;
	if(A.size() < 1) {
		return res;
	}

	for(int i = 1; i<A.size(); i++) {
		res = findPrefix(res,A[i]);
	}
	return res;
}
