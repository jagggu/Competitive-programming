/*
Unique Paths III
Problem Description
Given a matrix of integers A of size N x M . There are 4 types of squares in it:
1. 1 represents the starting square.  There is exactly one starting square.
2. 2 represents the ending square.  There is exactly one ending square.
3. 0 represents empty squares we can walk over.
4. -1 represents obstacles that we cannot walk over.
Find and return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.   


Problem Constraints
2 <= N * M <= 20
-1 <= A[i] <= 2


Input Format
The first argument given is the integer matrix A.


Output Format
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.


Example Input
Input 1:
A = [   [1, 0, 0, 0]
        [0, 0, 0, 0]
        [0, 0, 2, -1]   ]
Input 2:
A = [   [0, 1]
        [2, 0]    ]
 


Example Output
Output 1:
2
Output 2:
0
 


Example Explanation
Explanation 1: 
We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

*/





int xPos[] = {-1,0,1,0};
int yPos[] = {0,1,0,-1};

bool isSafe(vector<vector<int> > &A, int i, int j) {
    //cout<<i<<" "<<j<<" ; ";
    int rows = A.size();
    int cols = A[0].size();
    if(i<0 || i>=rows || j<0 || j>=cols) {
        //cout<<"Culprit1 ";
        return false;
    }
    
    if(A[i][j] == -1) {
        //cout<<"culprit2 ";
        return false;
    }
    return true;
}

void solveHelper(vector<vector<int> > &A, pair<int,int> currPos, int currCount, int zerosCount, int &ans) {
    int i = currPos.first;
    int j = currPos.second;
   // cout<<i<<" "<<j<<" Zerocount: "<<currCount<<" ";
    if(A[i][j] == 2) {
       // cout<<"checkPoint1 ";
       //cout<<currCount<<" "<<zerosCount<<" ; ";
        if(currCount == zerosCount) {
            ans++;
        }
        return;
    }
    A[i][j] = -1;
    
    for(int k = 0;k<4;k++) {
        
        if(isSafe(A,i+xPos[k],j+yPos[k])) {
           // cout<<"Reached";
            int newI = i+xPos[k];
            int newJ = j + yPos[k];
            
           // A[newI][newJ] = -1;
            pair<int,int> tmp = make_pair(newI,newJ);
            solveHelper(A,tmp,currCount+1,zerosCount,ans);
            
            
        }
        
    }
    A[i][j] = 0;
    
    
    
}

int Solution::solve(vector<vector<int> > &A) {
    if(A.size() < 1 || A[0].size() < 1) {
        return 0;
    }
    int rows = A.size();
    int cols = A[0].size();
    int zerosCount = 0;
    pair<int,int> startPos;
    for(int i = 0;i<rows;i++) {
        for(int j = 0;j<cols; j++) {
            if(A[i][j] == 1) {
                startPos = make_pair(i,j);
            }
            if(A[i][j] == 0) {
                zerosCount++;
            }
        }
    }
    int ans = 0;
//    cout<<startPos.first<<" "<<startPos.second<<" ";
     // cout<<zerosCount<<" ";
    solveHelper(A,startPos,-1,zerosCount,ans);  // -1 is becaz we don't need count destination pos as zero
    return ans;
}
