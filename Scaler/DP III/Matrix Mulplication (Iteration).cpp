#include<bits/stdc++.h>
using namespace std;

int findMinOperations(vector<int> &arr, int n) {
	vector<vector<int> > dp(n,vector<int>(n,0));

	for(int len = 2;len<n;len++) {
		for(int i = 1;i+len-1<n;i++) {

				int j = i+len-1;
				dp[i][j] = INT_MAX;
				for(int k = i;k<j;k++) {
					dp[i][j] = min(dp[i][j], arr[i-1]*arr[k]*arr[j] + dp[i][k]+dp[k+1][j]);
				}
		}
	}

	return dp[1][n-1];
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i = 0;i<n;i++) {
			cin>>arr[i];
		}

		int ans = findMinOperations(arr,n);
		cout<<ans<<endl;
	}
}