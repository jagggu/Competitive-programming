/*
NQueens
Problem Description
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.  Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

 


Problem Constraints
1 <= N <= 10


Input Format
First argument is an integer n denoting the size of chessboard


Output Format
Return an array consisting of all distinct solutions in which each element is a 2d char array representing a unique solution.


Example Input
Input 1:
n = 4


Example Output
Output 1:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]


Example Explanation
Explanation 1:
There exist only two distinct solutions to the 4-queens puzzle:

*/



void solveQueensHelper(vector<string> &board, int currRow, int rows, vector<bool> &visitedRow, vector<bool> &visitedCol, vector<bool> &visitedDiagonalLeft, vector<bool> &visitedDiagonalRight, vector<vector<string> > &ans) {
    if(currRow == rows) {
        ans.push_back(board);
        return;
    }
    for(int i = 0; i< rows; i++) {
        if(board[currRow][i] == '.' && !visitedRow[currRow] && !visitedCol[i] && !visitedDiagonalLeft[i-currRow+rows] && !visitedDiagonalRight[i+currRow]) {
            board[currRow][i] = 'Q';
            visitedCol[i] = true;
            visitedRow[currRow] = true;
            visitedDiagonalLeft[i-currRow+rows] = true;
            visitedDiagonalRight[i+currRow] = true;
            solveQueensHelper(board,currRow+1,rows,visitedRow,visitedCol,visitedDiagonalLeft,visitedDiagonalRight,ans);
            board[currRow][i] = '.';
            visitedCol[i] = false;
            visitedRow[currRow] = false;
            visitedDiagonalLeft[i-currRow+rows] = false;
            visitedDiagonalRight[i+currRow] = false;
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> board;
    string boardRow = "";
    for(int i = 0;i<A;i++) {
        boardRow+=".";
    }
    for(int i = 0;i<A;i++) {
        board.push_back(boardRow);
    }
    vector<vector<string> > ans;
    vector<bool> visitedRow(A,false);
    vector<bool> visitedCol(A,false);
    vector<bool> visitedDiagonalLeft(2*A,false);
    vector<bool> visitedDiagonalRight(2*A,false);
    solveQueensHelper(board,0,A,visitedRow,visitedCol,visitedDiagonalLeft,visitedDiagonalRight,ans);
    return ans;
}
