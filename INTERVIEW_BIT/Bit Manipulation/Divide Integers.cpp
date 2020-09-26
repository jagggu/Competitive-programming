#define ll long long int

int Solution::divide(int A, int B) {

	ll dividend = A;
	ll divisor = B;

	int sign = (A < 0) ^ (B < 0) ? -1 : 1;

	dividend = abs(dividend);
	divisor = abs(divisor);

	ll tmp = 0;
	ll quotient = 0;

	for (int i = 31; i >= 0; i--) {
		if ((tmp + (divisor << i)) <= dividend) {
			tmp = tmp + (divisor<<i);
			quotient = quotient | (1LL << i);
		}
	}
	quotient = sign * quotient;

	if (quotient > INT_MAX || quotient < INT_MIN) {
		return INT_MAX;
	}

	return quotient;

}
