/*
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.

*/


#define ll long long int


int powHelper(int a, int b, int c) {
	if(b <= 0) {
		return 1;
	}
	ll tmpAns;
	if(b&1) {
		tmpAns = (a%c * powHelper(a,b/2,c)%c)%c;
		return tmpAns;
	} else {
		tmpAns = powHelper(a,b/2,c);
		tmpAns = (tmpAns%c * tmpAns%c) %c;
		return tmpAns;
	}
}

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	//Recursion
	/*
	return powHelper(x,n,d);
	*/

	//Iterative
	if(x == 0) {
	    return 0;
	}
	ll ans = 1;
	ll base = x;
	while(n>0) {
		if(n&1) {
			ans = (ans%d * base%d) % d;
			n--;
		} else {
			base = (base%d * base%d) % d;
			n/=2;
		}
	}

	return ans<0?ans+d:ans;
}
