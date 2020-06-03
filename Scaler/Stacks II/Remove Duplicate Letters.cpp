/*

Remove Duplicate Letters
Given a string A consisting of lowercase English alphabets. Find and return lexicographically smallest string B after removing duplicate letters from A so that every letter appears once and only once.
Input Format
The only argument given is string A.
Output Format
Return lexicographically smallest string B after removing duplicate letters from A.
Constraints
1 <= length of the string <= 200000
A consists of lowercase English alphabets only. 
For Example
Input 1:
    A = "cbacdcbc"
Output 1:
    B = "acdb"

Input 2:
    A = "bcabc"
Output 2:
    B = "abc"

*/

string Solution::solve(string A) {

	stack<char> s;

	unordered_map<char,int> m;
	vector<bool> visited(26,false);

	for(auto ele : A ) {
		m[ele]++;
	}

	for(int i = 0;i<A.size();i++) {
		int charIndex = A[i] - 'a';
		if(visited[charIndex]) {

		    m[A[i]]--;  //We no longer using this char becaz we need to maintain order as well. So decrease the frequency of this char here.
			continue;
		}
	//	cout<<i<<' '<<A[i]<<endl;
		while(!s.empty() && s.top() > A[i] && m[s.top()] > 0) {
		//	m[s.top()]++;
			int index = s.top()-'a';
			visited[index] = false;
			s.pop();
		}
		s.push(A[i]);
		visited[A[i]-'a'] = true;
		m[A[i]]--;
	}
	string res;
	while(!s.empty()) {
		res += s.top();
		s.pop();
	}
	reverse(res.begin(),res.end());
	return res;
}
