// Problem Description
/*
    On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white 
    bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively.
    Uppercase characters represent white pieces, and lowercase characters represent black pieces.
    The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, 
    east, west, and south), then moves in that direction until it chooses to stop, reaches the
    edge of the board, or captures an opposite colored pawn by moving to the same square it 
    occupies.  Also, rooks cannot move into the same square as other friendly bishops.
    Return the number of pawns the rook can capture in one move.
 */ 

// straigntforward: first find the position of the rook, then check each of the four directions 
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int captures = 0;
        for ( int x = 0; x < 8; x++ ) 
            for ( int y = 0; y < 8; y++ ) {
                if ( board[x][y] == 'R' ) {
                    // move left 
                    for ( int left = x - 1; left >= 0; left-- ) {
                        if ( board[left][y] == 'p' ) {
                            captures++;
                            break;
                        } 
                        if ( board[left][y] == 'B' ) {
                            break;
                        }
                    }
                    // move right 
                    for ( int right = x + 1; right < 8; right++ ) {
                        if ( board[right][y] == 'p' ) {
                            captures++;
                            break;
                        }
                        if ( board[right][y] == 'B' ) {
                            break;
                        }
                    }
                    
                    // move up
                    for ( int up = y - 1; up >= 0; up-- ) {
                        if ( board[x][up] == 'p' ) {
                            captures++;
                            break;
                        }
                        if ( board[x][up] == 'B' ) {
                            break;
                        }
                    }
                    
                    // move down 
                    for ( int down = y + 1; down < 8; down++ ) {
                        if ( board[x][down] == 'p' ) {
                            captures++;
                            break;
                        }
                        if ( board[x][down] == 'B' ) {
                            break;
                        }
                    }
                }
            }
        return captures;
    }
};