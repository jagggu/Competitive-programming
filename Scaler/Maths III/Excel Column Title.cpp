/*
Excel Column Title
Problem Description

Given a positive integer A, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 


Problem Constraints
1 <= A <= 109



Input Format
First and only argument of input contains single integer A



Output Format
Return a string denoting the corresponding title.



Example Input
Input 1:

A = 3
Input 2:

 
A = 27


Example Output
Output 1:

"C"
Output 2:

"AA"


Example Explanation
Explanation 1:

 
3 corrseponds to C.
Explanation 2:

    1 -> A,
    2 -> B,
    3 -> C,
    ...
    26 -> Z,
    27 -> AA,
    28 -> AB 


    */



string Solution::convertToTitle(int A) {

	int num = A;
	string ans;
	while (num > 0) {
		int rem = num % 26;

		char ch;
		if (rem == 0) {
			ch = 'Z';
			num /= 26;

			num--;
		} else {
			rem--;
			num /= 26;
			ch = 'A' + (rem);
		}
		//cout<<rem<<' '<<ch<<endl;
		ans += ch;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}
