/*
Sum of minimum and maximum elements of all subarrays of size k
Given an array A of both positive and negative integers. Your task is to compute sum of minimum and maximum elements of all sub-array of size B. Note: Since the answer can be very large, you are required to return the sum module 1000000007. 
Input Format
The first argument denotes the array A.
The second argument denotes the value B
Output Format
Return an integer that denotes the required value.
Constraints
1 <= size of array A <= 100000
-1000000000 <= A[i] <= 1000000000
1 <= B <= size of array
** Example**
Example Input 1:
    A[] = {2, 5, -1, 7, -3, -1, -2}
    B = 4

Example Output 1:
    18
Explanation : 
    Subarrays of size 4 are : 
        {2, 5, -1, 7},   min + max = -1 + 7 = 6
        {5, -1, 7, -3},  min + max = -3 + 7 = 4      
        {-1, 7, -3, -1}, min + max = -3 + 7 = 4
        {7, -3, -1, -2}, min + max = -3 + 7 = 4   
        Sum of all min & max = 6 + 4 + 4 + 4 
                             = 18 

  */


#define ll long long

int Solution::solve(vector<int> &A, int B) {
	ll mod = 1000000007;
	deque<int> minQueue;
	deque<int> maxQueue;
	int i;
	for( i = 0;i<B;i++) {
		while(!maxQueue.empty() && A[maxQueue.back()]<=A[i]) {
			maxQueue.pop_back();
		}
		maxQueue.push_back(i);

		while(!minQueue.empty() && A[minQueue.back()] >= A[i]) {
			minQueue.pop_back();
		}
		minQueue.push_back(i);
	}
	int n = A.size();
	ll ans = 0;
	for(; i<n; i++) {
		int minEle = A[minQueue.front()];
		int maxEle = A[maxQueue.front()];
	//	cout<<minEle<<' '<<maxEle<<endl;
		ans = (ans%mod + minEle%mod + maxEle%mod)%mod;
		while(!minQueue.empty() && (i-minQueue.front()) >= B) {
			minQueue.pop_front();
		}
		while(!minQueue.empty() && A[minQueue.back()]>=A[i]) {
			minQueue.pop_back();
		}
		while(!maxQueue.empty() && (i-maxQueue.front()) >= B) {
			maxQueue.pop_front();
		}
		while(!maxQueue.empty() && A[maxQueue.back()]<=A[i]) {
			maxQueue.pop_back();
		}
		minQueue.push_back(i);
		maxQueue.push_back(i);
	}
	ans = (ans%mod + (A[minQueue.front()]+mod)%mod + A[maxQueue.front()]%mod)%mod;
	return ans%mod;
}
