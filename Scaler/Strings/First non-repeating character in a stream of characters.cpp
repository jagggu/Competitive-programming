/*
Help Others
First non-repeating character in a stream of characters
Given a string A denoting a stream of lowercase alphabets. You have to make new string B. B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. if no non-repeating character is found then append '#' at the end of B.
Input Format
The only argument given is string A.
Output Format
Return a string B after processing the stream of lowercase alphabets A.
Constraints
1 <= length of the string <= 100000
For Example
Input 1:
    A = "abadbc"
Output 1:
    "aabbdd"

    Explanation:
    "a"      -   first non repeating character 'a'
    "ab"     -   first non repeating character 'a'
    "aba"    -   first non repeating character 'b'
    "abad"   -   first non repeating character 'b'
    "abadb"  -   first non repeating character 'd'
    "abadbc" -   first non repeating character 'd'

Input 2:
    A = "abcabc"
Output 2:
    "aaabc#"

    Explanation
    "a"      -   first non repeating character 'a'
    "ab"     -   first non repeating character 'a'
    "abc"    -   first non repeating character 'a'
    "abca"   -   first non repeating character 'b'
    "abcab"  -   first non repeating character 'c'
    "abcabc" -   no non repeating character so '#'

 */



char firstNonRepeatChar(string &A, int &startPos, map<char,int> &m) {
		while(startPos < A.size()) {
			if(m.find(A[startPos]) != m.end()) {
				if(m[A[startPos]] <= 1) {
					return A[startPos];
				}
			} else {
				return '#';
			}
			startPos++;
		}
}

string Solution::solve(string A) {

	if(A.length() < 1) {
		return "";
	}
	map<char,int> m;
	m[A[0]] = 1;
	string res;
	res.push_back(A[0]);
	int startPos = 0;
	for(int i = 1;i<A.length();i++) {
		m[A[i]]++;
		char ch = firstNonRepeatChar(A,startPos,m);
		res.push_back(ch);
	}
	return res;
}
