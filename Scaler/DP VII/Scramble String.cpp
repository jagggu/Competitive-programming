
unordered_map<string,int> dp;

int isScrambleHelper(const string &s1, const string &s2) {
	if(s1 == s2) {
		return 1;
	}
	if(s1.size() != s2.size()) {
	    return 0;
	}
	string t = s1 + "#" + s2;
	if(dp.find(t) != dp.end()) {
		return dp[t];
	}
	int n = s1.size();
	for(int i = 1;i<s1.size();i++) {
		string str1 = s1.substr(0,i);
		string str2 = s2.substr(s2.size()-i);
		string str3 = s1.substr(i);
		string str4 = s2.substr(0,s2.size()-i);

		if(isScrambleHelper(str1,str2) && isScrambleHelper(str3,str4)) {
		  //string t = s1 + "#" + s2;
		  return  dp[t] =  true;
		}

		str1 = s1.substr(0,i);
		str2 = s2.substr(0,i);
		str3 = s1.substr(i);
		str4 = s2.substr(i);

		if(isScrambleHelper(str1,str2) && isScrambleHelper(str3,str4)) {
		    //string t = s1 + "#" + s2;
		    return  dp[t] =  true;
		}

		//return ans1 || ans2;

	}
	
	return  dp[t] =  false;
}

int Solution::isScramble(const string A, const string B) {

	if(A.size() != B.size()) {
		return 0;
	}

	dp.clear();

	return isScrambleHelper(A,B);
}
