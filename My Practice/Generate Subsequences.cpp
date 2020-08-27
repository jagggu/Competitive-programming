#include<bits/stdc++.h>
using namespace std;

void findSubseq(int indx, int n, int *arr, vector<int> tmp, vector<vector<int> > &res) {
	if(indx == n) {
		res.push_back(tmp);
		return;

	}
	tmp.push_back(arr[indx]);
	findSubseq(indx+1,n,arr,tmp,res);
	tmp.pop_back();
	findSubseq(indx+1,n,arr,tmp,res);
}

int main() {
	int arr[] = {3,1,5,8};

	vector<int> tmp;
	vector<vector<int> > res;

	findSubseq(0,4,arr,tmp,res);

	for(int i = 0;i<res.size();i++) {
		for(int j = 0;j<res[i].size();j++) {
			cout<<res[i][j]<<' ';
		}

		cout<<endl;
	}

}
