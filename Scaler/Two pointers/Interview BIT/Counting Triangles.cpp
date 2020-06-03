/*
You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4

*/


int Solution::nTriang(vector<int> &A) {
   
   int n = A.size();
   int mod = 1e9+7;
   int ans = 0;
   sort(A.begin(),A.end());
   for(int i = 0;i<n-2;i++) {
       for(int j = i+1;j<n;j++) {
           auto itr = lower_bound(A.begin()+j+1,A.end(),A[i]+A[j]);
           int tmp = itr - (A.begin()+j+1);
          // cout<<"Index: "<<itr-A.begin()<<" Len: "<<tmp<<endl;
           ans = (ans%mod + tmp%mod);
       }
   }
   return ans%mod;
}