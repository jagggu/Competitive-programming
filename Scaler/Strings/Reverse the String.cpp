/*
Reverse the String
Problem Description
Given a string A of size N. Return the string A after reversing the string word by word. NOTE:
A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.
 


Problem Constraints
1 <= N <= 105


Input Format
The only argument given is string A.


Output Format
Return the string A after reversing the string word by word.


Example Input
Input 1:
    A = "the sky is blue"
Input 2:
    A = "this is ib"  


Example Output
Output 1:
    "blue is sky the"
 Output 2:
    "ib is this"    


Example Explanation
Explanation 1:
    We reverse the string word by word so the string becomes "the sky is blue".

*/

void reverseString(string &str, int start, int end) {
	while(start<=end) {
		swap(str[start],str[end]);
		start++;
		end--;
	}
	
}

string Solution::solve(string A) {
	int index = 0;
	int i = 0;
	int n = A.size();

	//Removiing trail spaces
	while(i<n && A[i] == ' ') {
		i++;
	}
	int j = n-1;

	//Removing last spaces
	while(j>=0 && A[j] == ' ') {
		j--;
	}
	n = ++j;
	bool isSpaceOccured = false;
	for(;i<n; i++) {
		if(A[i] == ' ' && isSpaceOccured) {
			continue;
		}
		if(A[i] == ' ') {
			isSpaceOccured = true;
		}

		if(A[i] != ' ' && isSpaceOccured) {
			isSpaceOccured = false;
		}
		A[index++] = A[i];
	}

	int stringStartPos = 0;
	A = A.substr(0,index);

	//Initial Reverse
	reverseString(A,0,index-1);
	for(int i = 0;i<index;i++) {
		if(A[i] == ' ') {
			reverseString(A,stringStartPos,i-1);
			stringStartPos = i+1;
		}
	}
	//Last part of string 
	reverseString(A,stringStartPos,index-1);
	return A;
}
