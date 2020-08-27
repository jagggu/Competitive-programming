/*
Regular Expression Match
Problem Description

Implement wildcard pattern matching with support for ' ? ' and ' * ' for strings A and B.

' ? ' : Matches any single character.
' * ' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Problem Constraints
1 <= length(A), length(B) <= 104



Input Format
The first argument of input contains a string A.
The second argument of input contains a string B.



Output Format
Return 1 if the patterns match else return 0.



Example Input
Input 1:

 A = "aaa"
 B = "a*"
Input 2:

 A = "acz"
 B = "a?a"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 Since '*' matches any sequence of characters. Last two 'a' in string A will be match by '*'.
 So, the pattern matches we return 1.
Explanation 2:

 '?' matches any single character. First two character in string A will be match. 
 But the last character i.e 'z' != 'a'. Return 0.

 */



int Solution::isMatch(const string str, const string pat) {

	int strLen = str.size();
	int patLen = pat.size();

	vector<vector<bool> > regexMatch(patLen+1,vector<bool>(strLen+1));

	regexMatch[0][0] = true;

	for(int i = 1;i<=strLen;i++) {
		regexMatch[0][i] = false;
	}

	for(int i = 1;i<=patLen;i++) {
		if(pat[i-1] == '*') {
			regexMatch[i][0] = regexMatch[i-1][0];
		} else {
			regexMatch[i][0] = false;
		}
	}
        
        //cout<<"checkPoint1"<<endl;
    
	for(int i = 1;i<=patLen;i++) {
		for(int j = 1; j<= strLen; j++) {
		   // cout<<i<<' '<<j<<endl;
			if(pat[i-1] == '?') {
				regexMatch[i][j] = regexMatch[i-1][j-1];
			} else if(pat[i-1] == '*'){
				regexMatch[i][j] = regexMatch[i-1][j] || regexMatch[i][j-1];
			} else {
				if(str[j-1] == pat[i-1]) {
					regexMatch[i][j] = regexMatch[i-1][j-1];
				} else {
					regexMatch[i][j] = false;
				}
			}
		}
	}

	return regexMatch[patLen][strLen];
}
