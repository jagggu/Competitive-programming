/*
Maximum Difference on Tree
Problem Description

Given a tree with N nodes labeled from 1 to N.

Each node has a certain weight assigned to it given by an integer array A of size N.

Your task is to find the maximum difference in weights of two nodes where one node is a descendant of the other.

NOTE:

The tree is rooted at node labeled with 1.


Problem Constraints
2 <= N <= 105

-103 <= A[i] <= 103



Input Format
First argument is an integer array A of size N denoting the weight of each node.

Second argument is a 2-D array B of size (N-1) x 2 denoting the edge of the tree.



Output Format
Return an single integer denoting the maximum difference in weights of two nodes where one node is a descendant of the other.



Example Input
Input 1:

 A = [10, 5, 12, 6]
 B = [  [1, 2]
        [1, 4]
        [4, 3]
     ]
Input 2:

 A = [11, 12]
 B = [  [1, 2]
     ]


Example Output
Output 1:

 6
Output 2:

 1


Example Explanation
Explanation 1:

 The maximum difference occurs between the 3rd and 4th nodes. A[3] − A[4] = 12 - 6 = 6 .
Explanation 2:

 The maximum difference occurs between the 2nd and 1st nodes. A[2] − A[1] = 12 - 11 = 1 .

 */



unordered_map<int,bool> visited;

pair<int,int> solveHelper(int root, unordered_map<int,vector<int> > &adjList, vector<int> &val, int &ans) {
    
    visited[root] = true;

	vector<pair<int,int> > currAns;

	for(int child : adjList[root]) {
	    //cout<<"CheckPoint1"<<endl;
	    if(visited[child] == false) { 
		currAns.push_back(solveHelper(child,adjList,val,ans));
	    }
		
	}	

	int minVal = INT_MAX;
	int maxVal = INT_MIN;

	for(auto ansEle: currAns) {
		minVal = min(minVal,ansEle.first);
		maxVal = max(maxVal,ansEle.second);
	}

	int tmpAns = 0;
//	cout<<minVal<<' '<<maxVal<<endl;
	if(minVal != INT_MAX) {
		tmpAns = abs(val[root-1] - minVal);
	}

	if(maxVal != INT_MIN) {
		tmpAns = max(tmpAns, abs(val[root-1] - maxVal));
	}
	    
	
    
	ans = max(ans,tmpAns);

	return make_pair(min(minVal,val[root-1]),max(maxVal,val[root-1]));
}


int Solution::solve(vector<int> &A, vector<vector<int> > &B) {

	unordered_map<int,vector<int> > adjList;

	for(int i = 0;i<B.size();i++) {
		adjList[B[i][0]].push_back(B[i][1]);
		adjList[B[i][1]].push_back(B[i][0]);
	}
	
	visited.clear();
    
    //cout<<"Reached"<<endl;
	int ans = 0;
	
	

	solveHelper(1,adjList,A,ans);

	return ans;
}
