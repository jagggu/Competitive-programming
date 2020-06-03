/*
Passing game
There is a football event going on in your city. In this event, you are given N passes and players having ids between 1 and 1000000.
Initially some player with a given id had the ball in his possession. You have to make a program to display the id of the player who possessed the ball after exactly N passes. Description of the passes:
There are two kinds of passes:
ID
0
For the first kind of pass, the player in possession of the ball passes the ball to player with id=ID. For the second kind of a pass, the player in possession of the ball passes the ball back to the player who had passed the ball to him.
NOTE- In the second kind of pass "0" just means Back Pass.
Input
The first argument of the input contains the number N. 

The second argument of the input contains the number ID ( of the player possessing the ball in the very beginning).

The third argument is an array of size N having (ID/0).
Output
Return the "ID" of the player who possesses the ball after N passes.
Examples Input
10 23
86
63
60
0
47
0
99
9
0
0
Output
9
Explanation Testcase 1-
Initially, Player having  id=23  posses ball. After pass  1, Player having  id=86  posses ball. After pass  2, Player having  id=63  posses ball. After pass  3, Player having  id=60  posses ball. After pass  4, Player having  id=63  posses ball. After pass  5, Player having  id=47  posses ball. After pass 6, Player having  id=63  posses ball. After pass  7, Player having  id=99  posses ball. After pass  8, Player having  id=9 posses ball. After pass  9, Player having  id=99  posses ball. After pass  10, Player having  id=9  posses ball.

*/


int Solution::solve(int A, int B, vector<int> &C) {

	stack<int> s;
	s.push(B);
	for(auto ele : C) {
		if(ele != 0) {
			s.push(ele);
		} else {
			int ballPassFrom = s.top();
			s.pop();
			int ballPassTo = s.top();
			s.push(ballPassFrom);
			s.push(ballPassTo);
		}
	}
	return s.top();
}
