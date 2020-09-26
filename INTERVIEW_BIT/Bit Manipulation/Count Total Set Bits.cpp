#define ll long long int

ll MOD = 1e9+7;



int Solution::solve(int A) {

	ll ans = 0;

	int i = 0;

	ll power2 = 2;
	ll n = A+1;

	while(power2 <= n) {
		ll totalPairs = n/power2;

		ans += (totalPairs/2) * power2;

		ans += (totalPairs&1)? (totalPairs%power2) : 0;

		power2 = power2<<i;
	}

	return ans % MOD;
}
