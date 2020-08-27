/*
Gym Trainer
Problem Description

You are the trainer of a gym and there are A people who come to your gym.

Some of them are friends because they walk together, and some of them are friends because they talk together.
But people become possessive about each other, so a person cannot walk with one friend and talk with another. Although he can walk with two or more people or talk with two or more people.

You being the trainer, decided to suggest each one of the 2 possible diets. But friends, being friends will always have the same diet as all the other friends are having.

Find and return the number of ways you can suggest each of them a diet.

As the number of ways can be huge, return the answer modulo 109+7.

NOTE: If there is any person who walks with one person and talks with the another person, then you may return 0.



Problem Constraints
1 <= A, N, M <= 105

1 <= B[i][0], B[i][1], C[i][0], C[i][1] <= A



Input Format
The first argument contains an integer A, representing the number of people.
The second argument contains a 2-D integer array B of size N x 2, where B[i][0] and B[i][1] are friends because they walk together.
The third argument contains a 2-D integer array C of size M x 2, where C[i][0] and C[i][1] are friends because they talk together.



Output Format
Return an integer representing the number of ways to suggest one of the two diets to the people.



Example Input
Input 1:

 A = 4
 B = [
       [1, 2]
     ]
 C = [
       [3, 4]
     ]
Input 2:

 A = 3
 B = [
       [1, 2]
     ]
 C = [
       [1, 3] 
     ]


Example Output
Output 1:

 4
Output 2:

 0


Example Explanation
Explanation 1:

 There are four ways to suggest the diet:
 Diet-1 to (1, 2) and Diet-2 to (3, 4).
 Diet-1 to (1, 2) and Diet-1 to (3, 4).
 Diet-2 to (1, 2) and Diet-1 to (3, 4).
 Diet-2 to (1, 2) and Diet-2 to (3, 4).
 
Explanation 2:

 Person 1 walks with person 2 and talks with person 3. So, we will return 0.


*/



#define ll long long int

ll MOD = 1e9+7;

ll power(int base, int n) {
	ll ans = 1;

	while(n>0) {
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

int find(int node, vector<int> &parent) {
	if(parent[node] == node) {
		return node;
	}

	parent[node] = find(parent[node],parent);

	return parent[node];
}

int Solution::solve(int A, vector<vector<int> > &B, vector<vector<int> > &C) {

	vector<int> parent(A + 1);
	

	vector<int> size(A + 1, 1);
	

	for (int i = 1; i <= A; i++) {
		parent[i] = i;
	}

	vector<bool> visited(A + 1, false);

	for (int i = 0; i < B.size(); i++) {
		int src = B[i][0];
		int dest = B[i][1];
		visited[src] = true;
		visited[dest] = true;
		int c = find(src, parent);
		int d = find(dest, parent);

		if (c != d) {

			if(size[c] < size[d]) {
				swap(c,d);
			}

			parent[d] = c;
			size[c] += size[d];
		}
	}

	for(int i = 0;i<C.size();i++) {
		int src = C[i][0];
		int dest = C[i][1];

		if(visited[src]) {
			return 0;
		}

		if(visited[dest]) {
			return 0;
		}

		int c = find(src,parent);
		int d = find(dest,parent);

		if(c != d) {
			if(size[c] < size[d]) {
				swap(c,d);
			}

			parent[d] = c;
			size[c] += size[d];
		}
	}

	int components = 0;

	for(int i = 1;i<=A;i++) {

		if(parent[i] == i) {
			components++;
		}
	}

	int ans = power(2,components);

	return ans%MOD;
}
