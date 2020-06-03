#define ll long long int

struct TrieNode {
	TrieNode *children[2];
	int cnt;
}

TrieNode* newNode() {
	TrieNode *tmp = new TrieNode();
	tmp->children[0] = NULL;
	tmp->children[1] = NULL;
	tmp->cnt = 0;
}

void insert(TrieNode *root, int ele) {

	TrieNode *curr = root;
	for(int bitCount = 31; bitCount>=0; bitCount--) {
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
		curr->cnt++;
	}
	curr->cnt++;
}

ll findSubArrays(TrieNode *root, ll ele, int k) {
	TrieNode *curr = root;
	ll ans = 0;
	for(int bitCount = 31; bitCount>=0; bitCount--) {
		int bitNum;
		int bitK;
		if(ele & (1<<bitCount)) {
			bitNum = 1;
		} else {
			bitNum = 0;
		}

		if(k & (1<<bitCount)) {
			bitK = 1;
		} else {
			bitK = 0;
		}

		if(curr == NULL) {
			return 0;
		}

		if(bitNum == 1) {
			if(bitK == 1) {
				if(curr->children[1] != NULL) {
					ans += curr->children[1]->cnt;
				}
				curr = curr->children[0];
			} else {
				curr = curr->children[1];
			}
		} else {
			if(bitK == 1) {
				if(curr->children[0] != NULL) {
					ans += curr->children[0]->cnt;
				}
				curr = curr->children[1];
			} else {
				curr = curr->children[0];
			}
		}
	}

	return ans;
}

int Solution::solve(vector<int> &A, int B) {
	// Brute force Approach
	
	int n = A.size();
	if(n < 1) {
		return 0;
	}
	/*
	vector<int> pXor(n+1);
	pXor[0] = 0;
	for(int i = 1;i<=n;i++) {
		pXor[i] = pXor[i-1]^A[i-1];
	}

	int ans = 0;
	for(int j = 1;j<=n;j++) {
		for(int i = 0;i<j;i++) {
			int tmp = pXor[i]^pXor[j];
			if(tmp<B) {
				ans++;
			}
		}
	}

	return ans;
	*/



	ll mod = 1000000007;
	ll ans = 0;
	TrieNode *root = newNode();
	insert(root,0);
	ll currXor = 0;
	for(int i = 0;i<n;i++) {
		currXor = currXor ^ A[i];
		ll tmpAns = findSubArrays(root,currXor,B);
		ans = (ans%mod + tmpAns%mod) % mod;
		insert(root,currXor);
	}	

	return ans%mod;

}
