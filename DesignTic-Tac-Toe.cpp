// Problem Description
/*
 Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
Follow up:
Could you do better than O(n2) per move() operation?
*/

// after finishing the move, check whether the current player gains a winning position by checking the conditions 
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n,vector<int>(n,0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        int i = 0, j = 0, n = board.size();
        // resulting the current row to be the same ? 
        for ( j = 1; j < n; j++ )
        {
            if ( board[row][j] != board[row][j-1] )
                break;
        }
        if ( j == n )
            return player;
        // resulting the current column to be the same ? 
        for ( i = 1; i < n; i++ )
        {
            if ( board[i][col] != board[i-1][col] )
                break;
        }
        if ( i == n )
            return player;

        // if it is on the diagonal, the diagonal is the same as a result ? 
        if ( row == col )
        {
            for ( i = 1; i < n; i++ )
            {
                if ( board[i][i] != board[i-1][i-1] )
                    break;
            }
            if ( i == n )
                return player;
        }

         // if it is on the reverse diagonal, the reverse diagonal is the same as a result ? 
        if ( row + col == n-1 )
        {
            for ( i = 1; i < n; i++ )
            {
                if ( board[n-i-1][i] != board[n-i][i-1] )
                    break;
            }
            if ( i == n )
                return player;
        }
        
        // otherwise, it has not gained a winning position, no one wins after this move 
        return 0;
    }
    
private:
    vector<vector<int>> board;
};

// This solution tracks the current sum of each row, col, diag, and rev_diag. 
// If any of these lines belong to a player, then that player has won.
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows = vector<int>(n,0);
        cols = vector<int>(n,0);
        diag = 0;
        rev_diag = 0;
        N = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        // Player 1: increment 2: decrement 
        int add = player == 1 ? 1 : -1;
        rows[row] += add;
        cols[col] += add;
        diag += (row == col) ? add : 0;
        rev_diag += (row+col == N-1) ? add : 0;
        
        return (abs(rows[row]) == N || abs(cols[col]) == N || abs(diag) == N || abs(rev_diag) == N ) ? player : 0; 
    }
    
private:
    vector<int> rows, cols;
    int diag, rev_diag, N;
};