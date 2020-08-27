#define ll long long int

ll MOD = 1e9+7;

ll powerCal(ll base, ll n) {
	ll ans = 1;

	while(n > 0) {
		if(n&1) {
			ans = (ans%MOD * base%MOD) % MOD;
			n--;
		} else {
			base = (base % MOD * base % MOD) % MOD;
			n/=2;
		}
	}

	return ans;
}

int Solution::solve(int A) {

	vector<ll> fact(A+1);
	fact[0] = 1;

	for(int i = 1;i<=A;i++) {
		fact[i] = (fact[i-1]%MOD * i%MOD) % MOD;
	}

	ll ans = 0;

	ll n = A;

	for(ll i = 2;i<=A;i++) {

		ll den = fact[i]*fact[n-i];

		ll tmp1 = fact[n]/den;

		tmp1 = (tmp1%MOD * i%MOD * (i-1)%MOD * powerCal(2,i-2));

		ans = (ans%MOD + tmp1%MOD) % MOD;
	}

	return ans % MOD;

}
