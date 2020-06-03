/*
Ways to form Max Heap
Problem Description

Max Heap is a special kind of complete binary tree in which for every node the value present in that node is greater than the value present in it’s children nodes.

Find the number of distinct Max Heap can be made from A distinct integers.

In short, you have to ensure the following properties for the max heap :

Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.)
Every node is greater than all its children.
NOTE: If you want to know more about Heaps, please visit this link. Return your answer modulo 109 + 7.



Problem Constraints
1 <= A <= 100



Input Format
First and only argument is an inetegr A.



Output Format
Return an integer denoting the number of distinct Max Heap.



Example Input
Input 1:

 A = 4
Input 2:

 A = 10


Example Output
Output 1:

 3
Output 2:

 3360


Example Explanation
Explanation 1:

 Let us take 1, 2, 3, 4 as our 4 distinct integers
 Following are the 3 possible max heaps from these 4 numbers :
      4           4                     4
    /  \         / \                   / \ 
   3    2   ,   2   3      and        3   1
  /            /                     /    
 1            1                     2
Explanation 2:

 Number of distinct heaps possible with 10 distinct integers = 3360.


*/



#define ll long long int

#define MAX 106

#define MOD 1000000007
vector<int> dp(MAX);

vector<vector<int> > nck(MAX, vector<int>(MAX));

vector<int> LOG2(MAX);

ll power(ll base, ll expo) {
	ll ans = 1;

	while(expo > 0) {
		if(expo & 1) {
			ans = (ans%MOD * base%MOD) % MOD;
			expo--;
		} else {
			base = (base%MOD * base%MOD) % MOD;
			expo/=2;
		}
	}

	return ans%MOD;
}

ll getLeft(int n) {

	ll height = LOG2[n];

	ll lastLevelMax = power(2,height);

	ll lastLevelActual = n - (lastLevelMax-1);

	ll left;

	if(lastLevelActual >= (lastLevelMax/2)) {
		left = lastLevelMax - 1;
	} else {
		left = lastLevelMax - 1 - ((lastLevelMax/2) - lastLevelActual);
	}
	
	//cout<<n<<' '<<height<<' '<<lastLevelMax<<' '<<lastLevelActual<<' '<<left<<endl;

	return left;
}

ll choose(ll n , ll k) {
    //cout<<n<<' '<<k<<endl;
	if(k > n) {
		return 0;
	}

	if(n<=1) {
		return 1;
	}

	if(k == 0) {
		return 1;
	}

	if(nck[n][k] != -1) {
		return nck[n][k];
	}

	ll ans = (choose(n-1,k-1)%MOD + choose(n-1,k)%MOD) % MOD;

	return nck[n][k] = ans % MOD;



}

ll solveHelper(int n){
	if(n <= 1) {
		return 1;
	}

	if(dp[n] != -1) {
		return dp[n];
	}

	ll left = getLeft(n);
	
	//cout<<n<<' '<<left<<endl;

	ll ans = (choose(n-1,left)%MOD * solveHelper(left)%MOD * solveHelper(n-1-left)%MOD) % MOD;
        
   // cout<<choose(n-1,left)<<endl;
    
	return dp[n] = ans%MOD;




}

int Solution::solve(int A) {

	for(int i = 0;i<MAX;i++) {
		dp[i] = -1;
		for(int j=  0; j<MAX;j++) {
			
			nck[i][j] = -1;
		}
	}



	int currPower2 = 1;
	int currLog2 = -1;

	for(int i = 1;i<MAX;i++) {
		if(currPower2 == i) {
			currLog2++;
			currPower2 = currPower2 * 2;
		}
		LOG2[i] = currLog2;
	}

	ll ans = solveHelper(A);

	return ans%MOD;
}
