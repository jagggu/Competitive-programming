/*
Shortest Unique Prefix
Problem Description
Given a list of N words. Find shortest unique prefix to represent each word in the list. NOTE: Assume that no word is prefix of another. In other words, the representation is always possible   


Problem Constraints
1 <= Sum of length of all words <= 106


Input Format
First and only argument is a string array of size N.


Output Format
Return a string array B where B[i] denotes the shortest unique prefix to represent the ith word.


Example Input
Input 1:
 A = ["zebra", "dog", "duck", "dove"]
Input 2:
A = ["apple", "ball", "cat"]
  


Example Output
Output 1:
 ["z", "dog", "du", "dov"]
Output 2:
 ["a", "b", "c"]
  


Example Explanation
Explanation 1:
 Shortest unique prefix of each word is:
 For word "zebra", we can only use "z" as "z" is not any prefix of any other word given.
 For word "dog", we have to use "dog" as "d" and "do" are prefixes of "dov".
 For word "du", we have to use "du" as "d" is prefix of "dov" and "dog".
 For word "dov", we have to use "dov" as "d" and do" are prefixes of "dog".  
 
Explanation 2:
 "a", "b" and c" are not prefixes of any other word. So, we can use of first letter of each to represent.

*/



struct TrieNode {
	vector<int> children;
	string substr;
	int cnt;
};


void insert(string word, vector<TrieNode> &trie, int &nextAvailable) {
	int currIndex = 0;
	string tmp;
	for(char ch : word) {
		tmp+=ch;
		if(trie[currIndex].children.size() < 1) {
			vector<int> arr(26,-1);
			trie[currIndex].children = arr;
			//trie[currIndex].cnt = 0;
		//	cout<<"Tmp: "<<tmp<<endl;
		}
		if(trie[currIndex].children[ch-'a'] == -1) {
			trie[currIndex].children[ch-'a'] = nextAvailable++;
			

		}
		currIndex = trie[currIndex].children[ch-'a'];
		trie[currIndex].substr = tmp;
	//	cout<<"In func: "<<trie[currIndex].cnt<<endl;
		trie[currIndex].cnt++;
	}
}

string findPrefix(string word, vector<TrieNode> &trie) {
	int currIndex = 0;
	for(char ch : word) {
		currIndex = trie[currIndex].children[ch-'a'];
		if(trie[currIndex].cnt == 1) {
			return trie[currIndex].substr;
		}
	}

	return "";
}

vector<string> Solution::prefix(vector<string> &A) {
	vector<TrieNode> trie(1000007);	
    int nextAvailable = 1;
	
	vector<string> res;
	for(auto word : A) {
		insert(word,trie,nextAvailable);
	}
	   
	  
	   
	for(auto word : A) {
	    string prefix = findPrefix(word,trie);
	    res.push_back(prefix);
	}
   // nextAvailable = 1;
    //trie.clear();
	return res;
}
