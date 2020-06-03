/*
Sudoku
Problem Description
Write a program to solve a Sudoku puzzle by filling the empty cells. Empty cells are indicated by the character '.' You may assume that there will be only one unique solution.  A sudoku puzzle,   and its solution numbers marked in red.     


Problem Constraints
1 <= N <= 9


Input Format
First argument is an array of array of characters representing the Sudoku puzzle.


Output Format
Modify the given input to the required answer.


Example Input
Input 1:
A = [[53..7....], [6..195...], [.98....6.], [8...6...3], [4..8.3..1], [7...2...6], [.6....28.], [...419..5], [....8..79]]
    


Example Output
Output 1:
[[534678912], [672195348], [198342567], [859761423], [426853791], [713924856], [961537284], [287419635], [345286179]]
    


Example Explanation
Explanation 1:
Look at the diagrams given in the question.
    

*/




bool isSafe(vector<vector<char> > &board, int currRow, int currCol, char num) {
    int n = board.size();
    for(int i = 0;i<n;i++) {
        if(board[i][currCol] == num) {
            return false;
        }
        if(board[currRow][i] == num) {
            return false;
        }
    }
    int rn = sqrt(n);
    int sx = currRow - currRow%rn;
    int sy = currCol - currCol%rn;
    for(int i = sx; i<(sx+rn); i++) {
        for(int j = sy; j<(sy+rn);j++) {
            if(board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

void solveSudokuHelper(vector<vector<char> > &board, int currCell, int totalCells, vector<vector<bool> > &visitedRow, vector<vector<bool> > &visitedCol, vector<vector<bool> > &visitedBlock, bool &DONE) {
    if(currCell == totalCells) {
       // cout<<"checkPoint";
        DONE = true;
        return;
    }
    int n = board.size();
    int currRow = currCell/n;
    int currCol = currCell%n;
    
    if(board[currRow][currCol] != '.') {
        solveSudokuHelper(board,currCell+1,totalCells,visitedRow,visitedCol,visitedBlock,DONE);
        return;  //If not updates the value which is constant. We are not allowed to update the given values in the board
    }
    for(int k = 1; k<=9 && !DONE; k++) {
        char num = k+'0';
        if(isSafe(board,currRow,currCol,num) && !DONE) {
            board[currRow][currCol] = num;
            solveSudokuHelper(board,currCell+1,totalCells,visitedRow,visitedCol,visitedBlock,DONE);
            if(DONE) {
                return;
            }
            if(board[currRow][currCol]!='.') {
            board[currRow][currCol] = '.';
            }

        }
       // cout<<"Row: "<<currRow<<" Col: "<<currCol<<" VR: "<<visitedRow[currRow][k]<<" VC: "<<visitedCol[currCol][k]<<" ; ";
       /*
        if( !visitedRow[currRow][k] && !visitedCol[currCol][k] && !DONE) {
            //cout<<"checkPoint1 ";
           // int blockSize = sqrt(board.size());
            //int blockNum = (currRow/blockSize)*blockSize + (currCol/blockSize);
            
            if(!isBlockVisited(board,currRow,currCol,k+'0')) {
               // cout<<"checkPoint ";
                board[currRow][currCol] = k+'0';
                visitedCol[currCol][k] = true;
                visitedRow[currRow][k] = true;
               // visitedBlock[blockNum][k] = true;
                solveSudokuHelper(board,currCell+1,totalCells,visitedRow,visitedCol,visitedBlock,DONE);
                if(DONE) {
                    return;
                }
                if(!DONE) { 
                board[currRow][currCol] = '.';
                visitedCol[currCol][k] = false;
                visitedRow[currRow][k] = false;
                //visitedBlock[blockNum][k] = false;
                }
            }
        }
        */
    }
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() < 1 || A[0].size() < 1) {
        return;
    }
    int n = A.size();
    vector<vector<bool> > visitedRow(n,vector<bool>(10));
    vector<vector<bool> > visitedCol(n,vector<bool>(10));
    vector<vector<bool> > visitedBlock(n,vector<bool>(10));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<10;j++) {
            visitedRow[i][j] = false;
            visitedCol[i][j] = false;
            visitedBlock[i][j] = false;
        }
    }
    bool DONE = false;
    int totalCells = n*n;
  //  cout<<totalCells<<" ";
    solveSudokuHelper(A,0,totalCells,visitedRow,visitedCol,visitedBlock,DONE);

}
