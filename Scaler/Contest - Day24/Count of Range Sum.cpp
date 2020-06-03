
void merge(vector<int> &arr, int start, int mid, int end, int lower, int upper, ll &ans) {
	int left = mid+1;
	int right = end;
	for(int i = mid;i>=0;i--) {
		if(i == mid) {
			while(right>=mid+1 && arr[right]-arr[i] > upper) {
				right--;
			}
			while(left<=end && arr[left]-arr[i] < lower) {
				left++;
			}
			ans += (right-left+1);  //Count of subarrays
		} else {
			while(right>=mid+1 && arr[right]-arr[i] > upper) {
				right--;
			}
			while(left>end || (left>=mid+1 &&arr[left]-arr[i]>=lower)) {
				left--;
			}
			ans += (right-left+1);
		}
	}

	int index = 0;
	vector<int> tmp(end-start+1);
	int rStart = mid+1;
	while(start<=mid && rStart<=end) {
		if(arr[start] <= arr[end]) {
			tmp[index++] = arr[start++];
		} else {
			tmp[index++] = arr[rStart++];
		}
	}

	while(start<=mid) {
		tmp[index++] = arr[start++];
	}

	while(rStart<=end) {
		tmp[index++] = arr[rStart++];
	}

	for(int i = 0;i<tmp.size();i++) {
		arr[start+i] = tmp[i];
	}
}
	


void mergeSort(vector<ll> arr, int lower, int upper, int start, int end, ll &ans) {
	if(start>=end) {
		return;
	}
	int mid = start + (end-start)/2;
	mergeSort(arr,lower,upper,start,mid);  
	mergeSort(arr,lower,upper,mid+1,end);
	merge(arr,start,mid,end,lower,upper,ans);

}

int Solution::solve(vector<int> &A, int B, int C) {

	vector<ll> sumArr;
	ll sum = 0;
	for(int ele : A) {
		sum+=ele;
		sumArr.push_back(sum);
	}

	ll ans = 0;
	mergeSort(sumArr,B,C,0,A.size()-1,ans);
	return ans;

}
