struct TrieNode {
	TrieNode *children[26];

	bool isEnd;
};

TrieNode* newNode() {
	TrieNode *tmp = new TrieNode();
	tmp->isEnd = false;
	for (int i = 0; i < 26; i++) {
		tmp->children[i] = NULL;
	}

	return tmp;
}

vector<TrieNode> trie;
int nextAvailable;

void insert(TrieNode *root, string word) {
	TrieNode *curr = root;

	for (char ch : word) {
		int indx = ch - 'a';

		if (curr->children[indx] == NULL) {
			curr->children[indx] = newNode();
		}
		curr = curr->children[indx];

		//cout<<trie[currIndex].cnt<<endl;
	}
	curr->isEnd = true;
}

bool findRemainingPart(string word, int index, int n, TrieNode *root) {

	if (index == n) {
		if (root->isEnd) {
			return true;
		} else {
			return false;
		}
	}

	TrieNode *curr = root;

	int indx = word[i] - 'a';

	bool ans = false;


	if (root->children[indx]) {
		ans =  findRemainingPart(word,index+1,n,root->children[indx]);
	}

	return ans;
}

bool query(TrieNode *root, string word, int index, int n, int flag) {
	//int currIndex = 0;
	//int ans = 0;

	bool ans = false;
	if(index == n) {
		if(root->isEnd && flag) {
			return true;
		} 
		return false;
	}

	char ch = word[index];

	if(flag == 0) {
		for(char c = 'a';c<='z';c++) {
			if(c == ch) {
				ans = ans | query(root->children[c-'a'],word,index+1,n,flag);
			} else {
				ans = ans | query(root->children[c-'a'],word,index+1,n,1-flag);
			}
		}
	} else {
		if(root->children[ch-'a'] != NULL) {
			ans = ans | query(root->children[ch-'a'],word,index+1,n,flag);
		}
	}

	return ans;
}

string Solution::solve(vector<string> &A, vector<string> &B) {

	string res;
	int n = A.size();
	int m = B.size();

	TrieNode *root = newNode();

	for (int i = 0; i < n; i++) {
		// cout<<A[i]<<endl;
		string tmp = A[i];
		insert(root, tmp);
		//reverse(tmp.begin(),tmp.end());
		//insert(tmp);
	}

	for (int i = 0; i < m; i++) {
		string tmp = B[i];
		if (query(root, tmp,0,tmp.size(),0)) {
			res += "1";
		} else {
			res += "0";
		}
	}

	return res;


}
