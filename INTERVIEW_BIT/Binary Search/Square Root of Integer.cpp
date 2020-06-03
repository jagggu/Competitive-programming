#define ll long long int

int Solution::sqrt(int A) {

	ll start = 0;
	ll end = A;
	ll ans = 0;

	while(start <= end) {
		ll mid = start + (end-start)/2;
		ll tmp = mid*mid;
		if(tmp <= A) {
			ans = mid;
			start = mid+1;
		} else {
			end = mid-1;
		}
	}

	return ans;
}
