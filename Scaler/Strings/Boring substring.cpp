/*
Boring substring
Given a string A of lowercase English alphabets. Rearrange the characters of the given string A such that there is no boring substring in A. A boring substring has the following properties:
1. Its length is 2.
2. Both the characters are consecutive, for example - "ab", "cd", "dc", "zy" etc.
(If the first character is C then the next character can be either (C+1) or (C-1)).
Return 1 if it possible to rearrange the letters of A such that there are no boring substring in A, else return 0. 
Input Format
The only argument given is string A.
Output Format
Return 1 if it is possible to rearrange the letters of A such that there are no boring substrings in A, else return 0.
Constraints
1 <= |A| <= 100
For Example
Input 1:
    A = "abcd"
Output 1:
    1
    Explanation 1:
        String A can be rearranged into "cadb" or "bdac" 

Input 2:
    A = "aab"
Output 2:
    0
    Explanation 2:
        No arrangement of string A can make it free of boring substrings.

  */



bool isPossible(string str) {
	int n = str.length();

	for(int i = 0; i<n-1; i++) {
		if(abs(str[i] - str[i+1]) == 1) {
			return 0;
		} 
	}
	return 1;
}

int Solution::solve(string A) {

	string even,odd;

	for(int i = 0;i<A.size(); i++) {
		if(A[i]%2 == 0) {
			even+=A[i];
		} else {
			odd += A[i];
		}
	}
	
	//cout<<even<<' '<<odd<<endl;
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
	if(isPossible(even+odd)) {
		return 1;
	} else if(isPossible(odd+even)) {
		return 1;
	} else {
		return 0;
	}
}
