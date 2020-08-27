/*
Victory
Problem Description

Given three integers A, B, C.

Probability of India winning a match against Pakistan is 1/B.

Find the probability P of India winning Cth match in its Ath Match against Pakistan. If P = Q/R, return (Q * (R-1)) modulo 109+7.

NOTE: India should win Ath match and that should be Cth win of India in total.



Problem Constraints
1 <= A <= 109
1 <= B <= 102
1 <= C <= 109
1 <= C <= A
0 <= A - C <= 106


Input Format
The first argument given is integer A.

The Second argument given is integer B.

The Third argument given is integer C.



Output Format
Find the probability P of India winning Cth match in its Ath Match against Pakistan.

If P = Q/R, return (Q * (R-1)) modulo 109+7.



Example Input
Input 1:

 A = 2
 B = 2
 C = 2
Input 2:

 A = 3
 B = 3
 C = 2


Example Output
Output 1:

 250000002
Output 2:

 481481485


Example Explanation
Explanation 1:

 P = W W = ( 1/2 )*( 1/2 ) = 1/4 = (1) * (4-1) mod 109+7 = 250000002
Explanation 2:

 P = W L W + L W W = ( 1/3 ) * ( 2/3 ) * ( 1/3 ) + ( 2/3 ) * ( 1/3 ) * ( 1/3 ) = 4/27

 */



#define ll long long int

ll MOD = 1e9+7;

ll powerCal(ll base, ll n) {
	ll ans = 1;

	while(n > 0) {
		if(n&1) {
			ans = (ans%MOD * base%MOD) % MOD;
			n--;
		} else {
			base = (base%MOD * base%MOD) % MOD;
			n/=2;
		}
	}

	return ans%MOD;
}

ll inverseMod(ll num) {
	return powerCal(num,MOD-2) % MOD;
}

int Solution::solve(int A, int B, int C) {

	ll a = 1;
	ll b = 1;

	ll n = A-1;
	ll r = C-1;

	//As n>=r;
	//n!/r! = r+1*r+2 * ...n

	for(ll i = r+1;i<=n;i++) {
		a = (a%MOD * i%MOD) % MOD;
	}

	for(ll i = 1;i<=(A-C);i++) {
		b = (b%MOD * i%MOD) % MOD;
	}

	ll c = powerCal(B,A);
	ll d = powerCal(B-1,A-C);

	ll ans = 1;

	ans = (ans%MOD * a%MOD) % MOD;
	ans = (ans%MOD * d%MOD) % MOD;

	ll tmp = inverseMod(b);
	ans = (ans%MOD * tmp%MOD) % MOD;

	tmp = inverseMod(c);
	ans = (ans%MOD * tmp%MOD) % MOD;

	return ans%MOD;
}
