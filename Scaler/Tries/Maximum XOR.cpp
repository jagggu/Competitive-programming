/*
Maximum XOR
Problem Description
Given an array of integers A, find and return the maximum result of A[i] XOR A[j], where i, j are the indexes of the array.


Problem Constraints
1 <= length of the array <= 100000
0 <= A[i] <= 109


Input Format
The only argument given is the integer array A.


Output Format
Return an integer denoting the maximum result of A[i] XOR A[j].


Example Input
Input 1:
 A = [1, 2, 3, 4, 5]
Input 2:
 A = [5, 17, 100, 11]
  


Example Output
Output 1:
 7
Output 2:
 117
  


Example Explanation
Explanation 1:
 Maximum XOR occurs between element of indicies(0-based) 1 and 4 i.e. 2 ^ 5 = 7.
Explanation 2:
 Maximum XOR occurs between element of indicies(0-based) 1 and 2 i.e. 17 ^ 100 = 117.

 */



struct TrieNode {
	vector<int> children;
};

vector<TrieNode> trie;
int nextAvailable;
void insert(int ele) {
	int currIndx = 0;

	for(int i = 31;i>=0;i--) {
		int val;
		if(ele&(1<<i)) {
			val = 1;
		} else {
			val = 0;
		}
        
		if(trie[currIndx].children.size() < 1) {
			vector<int> arr(2,-1);
			trie[currIndx].children = arr;
		}

		if(trie[currIndx].children[val] == -1) {
			trie[currIndx].children[val] = nextAvailable++;
		}
		currIndx = trie[currIndx].children[val];
		//cout<<ele<<' '<<currIndx<<endl;
	}
}

bool isPrefix(int ele, int cnt) {
	int currIndx = 0;
	for(int i = 31;i>=cnt;i--) {
		int val;
		if(ele&(1<<i)) {
			val = 1;
		} else {
			val = 0;
		}

		if(trie[currIndx].children[val] == -1) {
			return false;
		}
		currIndx = trie[currIndx].children[val];
	}

	return true;
}

int Solution::solve(vector<int> &A) {

	int n = A.size();
	if(n < 1) {
		return 0;
	}
    nextAvailable = 1;
	trie.clear();
	trie.resize(32*n);

	insert(A[0]);

	int maxXor = 0;
//	cout<<n<<endl;
	for(int i = 1;i<n;i++) {
	   // cout<<"Original: "<<A[i]<<endl;
		int ele = A[i];
		int tmpAns = 0;
		for(int j = 31;j>=0;j--) {
			int val;
			if(ele & (1<<j)) {
				val = 1;
			} else {
				val = 0;
			}
            
			if(val == 1) {
				ele = ele ^ (1<<j);
				//int tmp = ele >> i;
				if(!isPrefix(ele,j)) {
					ele = ele | (1<<j);
				}
			} else {
				ele = ele | (1<<j);
                //int tmp = ele >> i;
				if(!isPrefix(ele,j)) {
					ele  = ele ^ (1<<j);
				}
			}
			

		}
      //  cout<<maxXor<<' '<<ele<<' '<<A[i]<<endl;
		maxXor = max(maxXor,ele^A[i]);
	//	cout<<"Array: "<<A[i]<<endl;
		insert(A[i]);
	}

    return maxXor;
}
