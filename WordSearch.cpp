// Problem Description
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
*/

// Dfs search toward the four directions 
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if ( board.empty() || board[0].empty() )
            return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > visited(m,vector<bool>(n,false));
        for ( int i = 0; i < m; i++ )
            for ( int j = 0; j < n; j++ )
                if ( search(board,0,i,j,word,visited) )
                    return true;
        return false;
    }
    
    bool search(vector<vector<char>> &board, int idx, int r, int c, const string word, vector<vector<bool>> &visited )
    {
        int m = board.size(), n = board[0].size(); 
        if ( idx == word.size() )
            return true;
        if ( r < 0 || c < 0 || r >= m || c >= n || visited[r][c] || board[r][c] != word[idx] )
            return false;
        visited[r][c] = true;
        bool res =  search(board,idx+1,r-1,c,word,visited) || 
                search(board, idx+1,r+1,c,word,visited) ||
                search(board,idx+1,r,c+1,word,visited) ||
                search(board,idx+1,r,c-1,word,visited);
        visited[r][c] = false;
        return res;
    }
};