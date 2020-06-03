/*
Ways to form Max Heap 2
Problem Description

Max heap is a special kind of complete binary tree in which for every node the value present in that node is greater than the value present in it’s children nodes.

Given an array A of size N consisting of N - 1 distinct elements. In other words there is exactly one element that is repeated.
It is given that the element that would repeat would be either the maximum element or the minimum element.

Find the number of structurally different Max heaps possible using all the N elements of the array i.e. Max heap of size N.

As final answer can be very large return your answer modulo 109 + 7.



Problem Constraints
1 <= N <= 1000



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the number of structurally different Max heaps possible modulo 109 + 7.



Example Input
Input 1:

 A = [1, 5, 5]
Input 2:

 A = [2, 2, 7]


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 The possible max heaps using the given elements are:- First: 5 on the root. 1 as the left child of root and 5 as the right child of the root.   
                5
              /   \
            1       5
 Second: 5 on the root. 5 as the left child of root and 1 as the right child of the root.
                5
              /   \
            5       1            
Explanation 2:

 There is only one possible max heaps: 7 on the root. 2 as the left child of root and 2 as the right child of the root.   
                7
              /   \
            2       2

  */







#define ll long long int

#define MAX 1006

#define MOD 1000000007
vector<int> dp(MAX);
vector<int> dp1(MAX);

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

ll solveHelper2(int n) {

	if(n<2) {
		return 0;
	}

	if(n < 4) {
		return 1;
	}

	if(n == 4) {
		return 2;
	}

	if(n == 5) {
		return 4;
	}

	if(dp1[n] != -1) {
		return dp1[n];
	}

	ll left = getLeft(n);
	ll right = n-1-left;
	ll ans = (choose(n-3,left-2)%MOD * solveHelper2(left)%MOD * solveHelper(n-1-left)%MOD) %MOD;

	ans = (ans%MOD + (choose(n-3,left-1)%MOD * solveHelper(left)%MOD * solveHelper(right)%MOD) % MOD) % MOD;

	ans = (ans%MOD + (choose(n-3,right-2)%MOD * solveHelper(left)%MOD * solveHelper2(right)%MOD)%MOD) % MOD;

	return dp1[n] = ans; 
}

int Solution::solve(vector<int> &A) {

	for(int i = 0;i<MAX;i++) {
		dp[i] = -1;
		dp1[i] = -1;
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

	int maxEle = INT_MIN;
	int maxCount = 0;
	for(int ele : A) {
		maxEle = max(maxEle,ele);
	}

	for(int ele : A) {
		if(ele == maxEle) {
			maxCount++;
		}
	}

	ll ans;
	if(maxCount == 2) {
		ans = solveHelper(A.size());
	} else {
		ans = solveHelper2(A.size());
	}

	//ll ans = solveHelper(n);

	return ans%MOD;
}
