/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

*/




class Solution {
public:

	bool isSafe(vector<vector<char> > &board, int i, int j, int rows, int cols, char ch) {

		if(i<0 || i>=rows || j<0 || j>=cols || board[i][j] != ch) {
			return false;
		}

		return true;
	}

	bool isWordExist(vector<vector<char> > &board, int i, int j, int rows, int cols, string &word, int index) {
		
		if(index == word.size()) {
			return true;
		}

		if(!isSafe(board,i,j,rows,cols,word[index])) {
			return false;
		}

		char ch = board[i][j];
		board[i][j] = '#';

		bool ans = isWordExist(board,i-1,j,rows,cols,word,index+1) ||
				   isWordExist(board,i,j+1,rows,cols,word,index+1) ||
				   isWordExist(board,i+1,j,rows,cols,word,index+1) ||
				   isWordExist(board,i,j-1,rows,cols,word,index+1);

		board[i][j] = ch;
		return ans;
	}

    bool exist(vector<vector<char>>& board, string word) {
  		
  		if(board.size() < 1 || board[0].size() < 1) {
  			return false;
  		}   

  		if(word.size() < 1) {
  			return true;
  		}

  		int rows = board.size();
  		int cols = board[0].size();

  		for(int i = 0; i<rows; i++) {
  			for(int j = 0; j<cols; j++) {
  				if(isWordExist(board,i,j,rows,cols,word,0)) {
  					return true;
  				}
  			}
  		}

  		return false;

    }
};