/*
K-th smallest in a range
Problem Description
Given an integer array A of size N.
You are also given Q queries denoted by 2D array B of size Q x 3 where B[i][0] denotes L, B[i][1] denotes R and B[i][2] denotes K. For each query, find the Kth smallest in the range from array index L to R (both inclusive).  


Problem Constraints
1 <= N, Q <= 50000 -109 <= A[i] <= 109 1 <= L <= R <= N 1 <= K <= R - L + 1  


Input Format
First argument is an integer array A of size N.
Second argument is a 2D array B of size Q x 3.


Output Format
Return an integer array of size Q, denoting the output of each query.


Example Input
Input 1:
 A = [1, -2, 6, 1, 3]
 B = [
       [2, 4, 2]
       [1, 5, 4]
       [3, 3, 1]
     ]
Input 2:
 A = [23, -12, -16, 1, 9, 2]
 B = [
       [3, 6, 1]
       [1, 4, 4]
     ]
 


Example Output
Output 1:
 [1, 3, 6]
Output 2:
 [-16, 23]
 


Example Explanation
Explanation 1:
 For 1st query, array in the range (2, 4) is [-2, 6, 1] and 2nd smallest element will be 1.
 For 2nd query, array in the range (1, 5) is [1, -2, 6, 1, 3] and 4th smallest element will be 3.
 For 3rd query, array in the range (3, 3) is [6] and 1st smallest element will be 6.
Explanation 2:
 For 1st query, array in the range (3, 6) is [-16, 1, 9, 2] and 1st smallest element will be -16.
 For 2nd query, array in the range (1, 4) is [23, -12, -16, 1] and 4th smallest element will be 23.
 
 */


vector<vector<int> > segTree;

bool myComp(pair<int,int> p1, pair<int,int> p2) {
    return p1.first < p2.first;
}

void buildTree(int node, int start, int end, vector<pair<int,int> > &A) {
    if(start == end) {
        segTree[node].push_back(A[start].second);
        return;
    }

    int mid = start + (end-start)/2;

    buildTree(2*node,start,mid,A);
    buildTree(2*node+1,mid+1,end,A);

   // int n = segTree[2*node].size();
    //int m = segTree[2*node+1].size();
    //segTree[node].resize(m+n);

    merge(segTree[2*node].begin(),segTree[2*node].end(),segTree[2*node+1].begin(),segTree[2*node+1].end(),back_inserter(segTree[node]));

}

int query(int node, int start, int end, int l, int r, int k) {
    if(start == end) {
        return segTree[node][0];
    }

    int lower = lower_bound(segTree[2*node].begin(),segTree[2*node].end(),l) - segTree[2*node].begin();
    int upper = upper_bound(segTree[2*node].begin(),segTree[2*node].end(),r) - segTree[2*node].begin();

    int count = upper-lower;

    int mid = start + (end-start)/2;

    if(count>=k) {
        return query(2*node,start,mid,l,r,k);
    } else {
        return query(2*node+1,mid+1,end,l,r,k-count);
    }
}

vector<int> Solution::solve(vector<int>&A, vector<vector<int>>&B){
    
    int n = A.size();
    segTree.clear();
    segTree.resize(4*n);

    vector<pair<int,int> > arr;
    for(int i = 0;i<n;i++) {
        arr.push_back(make_pair(A[i],i));
    }

    sort(arr.begin(),arr.end(),myComp);
    
   
    
   // cout<<"checkPOint"<<endl;
    buildTree(1,0,n-1,arr);
   // cout<<"checkPoint2"<<endl;
    vector<int> res;
    for(int i = 0;i<B.size();i++) {
        int indx = query(1,0,n-1,B[i][0]-1,B[i][1]-1,B[i][2]);
        //cout<<indx<<endl;
        res.push_back(A[indx]);
    }

    return res;
}