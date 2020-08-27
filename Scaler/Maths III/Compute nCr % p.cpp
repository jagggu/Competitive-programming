/*
Compute nCr % p
Problem Description

Given three integers A, B and C, where A represents n, B represents r and C represents p and p is a prime number greater than equal to n, find and return the value of nCr % p where nCr % p = (n! / ((n-r)! * r!)) % p.

x! means factorial of x i.e. x! = 1 * 2 * 3... * x.

NOTE: For this problem, we are considering 1 as a prime.



Problem Constraints
1 <= A <= 106
1 <= B <= A
A <= C <= 109+7


Input Format
The first argument given is the integer A ( = n).
The second argument given is the integer B ( = r).
The third argument given is the integer C ( = p).



Output Format
Return the value of nCr % p.



Example Input
Input 1:

 A = 5
 B = 2
 C = 13
Input 2:

 A = 6
 B = 2
 C = 13


Example Output
Output 1:

 10
Output 2:

 2


Example Explanation
Explanation 1:

 nCr( n=5 and r=2) = 10.
 p=13. Therefore, nCr%p = 10.


*/


#define ll long long int

ll powerCal(ll base, ll n, ll p) {
	ll ans = 1LL;

	while(n > 0) {
		if(n&1) {
			ans = (ans%p * base%p) % p;
			n--;
		} else {
			base = (base%p * base%p) % p;
			n/=2;
		}
	}

	return ans%p;
}

ll inverseMod(ll num, ll p) {
	return powerCal(num,p-2,p) % p;
}

int Solution::solve(int A, int B, int C) {

	ll n = A;
	ll r = B;
	ll p = C;
	
	if(r == 0) {
	    return 1%p;
	}
	
	if(r == 1) {
	    return n%p;
	}

	//As n>=r n!/r! --> (r+1)*(r+2)*(r+3)*....n

	ll a = 1;
	for(ll i = r+1;i<=n;i++) {
		a = (a%p * i%p) % p;
	}

	ll b = 1;

	for(ll i = 1;i<=(n-r);i++) {
		b = (b%p * i%p) % p;
	}

	ll tmp = inverseMod(b,p);

	ll ans = (a%p * tmp%p) % p;

	return ans;
}
