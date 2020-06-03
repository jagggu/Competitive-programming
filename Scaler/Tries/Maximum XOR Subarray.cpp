
#define ll long long int

struct TrieNode {
	TrieNode *children[2];
	int pos;
};

TrieNode* newNode() {
	TrieNode *tmp = new TrieNode();
	tmp->pos = 0;
	tmp->children[0] = NULL;
	tmp->children[1] = NULL;
	return tmp;
}

int maxBits = 0;

//vector<vector<int> > trie;
//int nextAvailable;

void insert(TrieNode *root, int ele, int pos) {
	//int currIndex = 0;
	TrieNode *curr = root;
	for(int bitCount = maxBits; bitCount>=0; bitCount--) {
		int val;
		if(ele & (1<<bitCount)) {
			val = 1;
		} else {
			val = 0;
		}

		

		if(curr->children[val] == NULL) {
			curr->children[val] = newNode();
		}
		curr = curr->children[val];
	//	cout<<trie[currIndex].size()<<endl;
		curr->pos = pos;
	}
	curr->pos = pos;

}

bool isPrefix(TrieNode *root, int ele, int bitRange, int &index) {
	//int currIndex = 0;
	TrieNode *curr = root;
	for(int bitCount = maxBits; bitCount>=bitRange;bitCount--) {
		int val;
		if(ele & (1<<bitCount)) {
			val = 1;
		} else {
			val = 0;
		}
		if(curr->children[val] == NULL) {
			return false;
		}
		curr = curr->children[val];
		index = curr->pos;
	}
	index = curr->pos;
	return true;
}

ll findEle(TrieNode *root, int ele, int &index) {
	for(int bitCount = maxBits; bitCount>=0; bitCount--) {
		int val;
		if(ele & (1<<bitCount)) {
			val = 1;
		} else {
			val = 0;
		}

		if(val == 1) {
			ele = ele ^ (1<<bitCount);

			if(!isPrefix(root,ele,bitCount,index)) {
				ele = ele | (1<<bitCount);
			}
		} else {
			ele = ele | (1<<bitCount);

			if(!isPrefix(root,ele,bitCount,index)) {
				ele = ele ^ (1<<bitCount);
			}
		}
	}

	return ele;
}


vector<int> Solution::solve(vector<int> &A) {



	vector<int> res;
	int n = A.size();
    //cout<<"checkPoint2";
	//trie.clear();
	//trie.resize(32*(n+1),vector<int>(3,-1));
	//nextAvailable = 1;

	TrieNode *root = newNode();

	if(n < 1) {
		return res;
	}

	ll tmp = 0;
	for(auto ele : A) {
		tmp = tmp ^ ele;
		int currBits = (int)log2(tmp)+1;
		maxBits = max(maxBits,currBits);
	}


	ll currPXor = A[0];
	int start = 0;
	int end = 0;
    //cout<<"checkpOint1";
    ll t = 0
	insert(root,t,0);
	insert(root,A[0],1);
	ll maxXor = 0;
//	cout<<"currXor: "<<currPXor<<' '<<" index: 1"<<endl;
	for(int i = 1;i<n;i++) {
	    //cout<<"reahed";
		int index = 0;
		currPXor = currPXor ^ A[i];
	//	cout<<"currXor: "<<currPXor<<" index: "<<i+1<<endl;
		ll eleWithMaxXor = findEle(root,currPXor,index);
        
		ll tmpXor = currPXor ^ eleWithMaxXor;
   // cout<<"maximumXor: "<<eleWithMaxXor<<" tmpXor: "<<tmpXor<<" index: "<<index;
    
		if(tmpXor > maxXor) {
			maxXor = tmpXor;
			start = index+1;
			end = i+1;
		}
		
	//	cout<<" start: "<<start<<" end: "<<end<<endl;

		insert(root,currPXor,i+1);

	}
    if(start == 0 && end == 0) {
        start++;
        end++;
    }
	res.push_back(start);
	res.push_back(end);
	return res;
}
