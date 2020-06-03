/*
Window String
Problem Description
Given a string A and a string B, find the window with minimum length in A which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in A should be at least N. Note:
If there is no such window in A that covers all characters in B, return the empty string.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index )
  


Problem Constraints
1 <= size(A), size(B) <= 106


Input Format
First argument is a string A.
Second argument is a string B.


Output Format
Return a string denoting the minimum window.


Example Input
A = "ADOBECODEBANC"
B = "ABC"


Example Output
"BANC"


Example Explanation
"BANC" is a substring of A which contains all characters of B.

*/


string Solution::minWindow(string A, string B) {

	int count = 0;
	int BLen = B.length();

	int resL = -1, resR = -1;
    //cout<<"Check Point 2";
	unordered_map<char,int> m;
	unordered_map<char,int> Amap;
	int minLen = INT_MAX;
	for(char ch : B) {
		m[ch]++;
	}
	int j = 0;
    //cout<<"Check Point 1";
	for(int i = 0;i<A.size();i++) {
		Amap[A[i]]++;
		if(m.find(A[i]) != m.end()) {
			if(Amap[A[i]] <= m[A[i]]) {
				count++;
			}
		}
    
    
		if(count >= BLen) {
		  //  cout<<"Reached";
		  
		    int currLen = i-j+1;
		    
				if(currLen < minLen) {
					minLen = currLen;
					resL = j;
						resR = i;
					
				} else if(currLen == minLen) {
				    if(resL == -1 || j<resL) {
						resL = j;
						resR = i;
					}
				}
				
			//	cout<<j<<' '<<i<<endl;
			while(m.find(A[j]) == m.end() || m[A[j]] < Amap[A[j]] || minLen == INT_MAX) {
			    //cout<<"Reached"<<endl;
                
                Amap[A[j]]--;
				j++;
				
					 currLen = i-j+1;
				if(currLen < minLen) {
				   // cout<<j<<' '<<i<<endl;
					minLen = currLen;
					resL = j;
						resR = i;
					
				} else if(currLen == minLen) {
				    if(resL == -1 || j<resL) {
						resL = j;
						resR = i;
					}
				}
						
			}


		}
		
	}

	string res;
	if(resL == -1) {
	   // cout<<"Check Point 3";
		return res;
	}
	for(int i = resL; i<=resR;i++) {
		res.push_back(A[i]);
	}
	return res;
}
