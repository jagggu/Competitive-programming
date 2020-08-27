#include<bits/stdc++.h>

using namespace std;

vector<int> ans;

void findKSubSetSum(vector<int> &arr, int indx, int n,int sum, int k, vector<int> tmp) {
	if(ans.size() > 0) {
		return;
	}

	if(indx>=n) {
		return;
	}
	if(sum<0) {
		return;
	}
	if(k<0) {
		return;
	}
	if(sum == 0 && k == 0) {
		ans = tmp;
	}

	tmp.push_back(arr[indx]);
	findKSubSetSum(arr,indx+1,n,sum-arr[indx],k-1,tmp);
	tmp.pop_back();
	findKSubSetSum(arr,indx+1,n,sum,k,tmp);
}

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    
    int n,k,sum;
    cin>>n>>k>>sum;

    vector<int> arr(n);
    for(int i = 0;i<n;i++) {
    	cin>>arr[i];
    }

    ans.clear();
    vector<int> tmp;
    findKSubSetSum(arr,0,n,sum,k,tmp);
    return ans;
    return 0;
}