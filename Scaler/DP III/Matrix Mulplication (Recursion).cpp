#include <bits/stdc++.h>
using namespace std;

int findMinOperations(vector<int> &arr, int i, int j, vector<vector<int> > &dp) {
	if(i == j) {
		return 0;
	}

	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	int ans = INT_MAX;

	for(int k = i;k<j;k++) {
		
		int cnt = findMinOperations(arr,i,k,dp) + findMinOperations(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];

		ans = min(ans,cnt); 
	}

	return dp[i][j] = ans;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i = 0;i<n;i++) {
			cin>>arr[i];
		}

		vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
		int ans = findMinOperations(arr,1,n-1,dp);
		cout<<ans<<endl;

	}
}