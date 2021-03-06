/*
Equal Strings
Problem Description
Given two strings A and B each of size N consisting of lowercase alphabets. You can perform the following operations any number of time:  
Select any two characters in string A and swap the characters.
Select any two characters in string B and swap the characters.
Select a character in string A and select a character in string B. Swap the characters from both strings.
 Return 1 if it possible to make strings equal else return 0.  


Problem Constraints
1 <= N <= 105


Input Format
First argument is a string A of size N. First argument is a string B of size N.  


Output Format
Return 1 if it possible to make strings equal else return 0.


Example Input
Input 1:
 A = "adbc"
 B = "abcd"
Input 2:
 A = "abbc"
 B = "aabc"


Example Output
Output 1:
 1
Output 2:
 0
 


Example Explanation
Expanation 1:
 We can make the string A equal to B by first swapping 'd' and 'c' of string A. So the string becomes "acbd".
 Then swap 'b' and 'c' of string A. So the final string becomes "abcd".
Explanation 2:
 There is no possible way in which we can make the strings equal.

 */


int Solution::solve(string A, string B) {
	int Alen = A.size();
	int Blen = B.size();
	if(Alen != Blen) {
		return 0;
	}
	unordered_map<char,int> m;
	for(int i = 0; i<Alen;i++) {
		m[A[i]]++;
		m[B[i]]--;
	}   
	

	for(auto itr = m.begin();itr != m.end(); itr++) {
		if(itr->second & 1) {
			return 0;
		}
	}
	return 1;
}
