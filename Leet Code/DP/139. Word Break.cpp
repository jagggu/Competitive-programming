class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
  		
  		stack<int> st;
  		st.push(0);
  		set<string> duplicates;
  		for(int i = 1;i<=s.size();i++) {
  			int lastIndx = st.top();
  			string str = s.substr(lastIndx,i-lastIndx);
  			auto itr = find(wordDict.begin(),wordDict.end(),str);

  			if(itr != wordDict.end()) {
  				st.push(i);
  			}
  		}

  		return st.top() == s.size();      
    }
};