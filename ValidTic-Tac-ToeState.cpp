// Problem Description
/*
 A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true
Note:

board is a length-3 array of strings, where each string board[i] has length 3.
Each board[i][j] is a character in the set {" ", "X", "O"}.
*/

// This problem requires to carefully check the conditions dictated by the game rules:
// 1. At any time, the number of 'X' is either equal to or one more then the number of 'O'
// 2. If 'X' wins, then 'X' performs the last step and because it is the first to go, the number of 'X' must be one more than 'O'
// 2. If 'O' wins, then 'O' performs the last step and because 'X' is the first to go, then they must be equal 
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int Xcount = 0, Ocount = 0;
        for ( int i = 0; i < board.size(); i++ )
            for ( int j = 0; j < board[0].size(); j++ )
            {
                if ( board[i][j] == 'X' )
                    Xcount++;
                if ( board[i][j] == 'O' )
                    Ocount++;
            }
        if ( !(Xcount == Ocount || Xcount == Ocount + 1) )
            return false;
    
        if ( IsPlayerWin(board,'X') && Xcount != Ocount + 1 )
            return false;
        
        if ( IsPlayerWin(board,'O') && Xcount != Ocount )
            return false;
        
        return true;
    }
    
    bool IsPlayerWin( vector<string> &board, char P )
    {
        // check rows 
        int r = board.size(), c = board[0].size();
        for ( int i = 0; i < r; i++ )
        {
            bool FullRow = true;
            for ( int j = 0; j < c; j++ )
            {
                FullRow &= board[i][j] == P;
            }
            if ( FullRow )
                return true;
        }

        // check columns 
        for ( int i = 0; i < c; i++ )
        {
            bool FullCol = true;
            for ( int j = 0; j < r; j++ )
            {
                FullCol &= board[j][i] == P;
            }
            if ( FullCol )
                return true;
        }
        
        // check diagonal   
        bool Diagonal = true;
        for ( int i = 0; i < r; i++ )
            Diagonal &= board[i][i] == P;
        if ( Diagonal )
            return true;
        
        // check reverse diagonal 
        bool ReverseDiagonal = true;
        for ( int i = 0; i < r; i++ )
            ReverseDiagonal &= board[i][r-i-1] == P;
        if ( ReverseDiagonal )
            return true;
        
        return false;

    }
};