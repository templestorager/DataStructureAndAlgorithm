// Problem Description
/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/

// We can use brute force approach by call word search for each of the word in the dictionary 
// The following approach uses Trie data structure. 
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if ( words.empty() || board.empty() || board[0].empty() )
            return res;
        int m = board.size(), n = board[0].size(); 
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        Trie T;
        for ( auto &w : words )
            T.InsertWord(w);
        for ( int i = 0; i < m; i++ )
            for ( int j = 0; j < n; j++ )
            if ( T.GetRoot()->m[board[i][j]] )
            {
                search(board, T.GetRoot()->m[board[i][j]],i,j,visited,res);
            }
        return res;
    }
private:
    struct TrieNode {    
        string str;     // it's the word if this node represents a valid word 
        unordered_map<char, TrieNode *> m;
        TrieNode() : str("") {
            m.clear();
        }
    };
    class Trie {
        TrieNode *root;
    public:
        Trie () : root( new TrieNode()) {}
        void InsertWord( const string word )
        {
            TrieNode * p = root;
            for ( auto &a : word )
            {
                if ( !p->m[a] )
                    p->m[a] = new TrieNode();
                p = p->m[a];
            }
            p->str = word;
        }
        TrieNode* GetRoot() {
            return root;
        }
    };
    void search( const vector<vector<char>> &board, TrieNode *root, const int r, const int c, vector<vector<bool>> &visited, vector<string> &res )
    {
        int m = board.size(), n = board[0].size();
        if ( !root->str.empty() )
        {
            res.push_back(root->str);
            root->str.clear();
        }
        
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        visited[r][c] = true;
        for ( auto &d : dir )
        {
            int nx = d[0] + r;
            int ny = d[1] + c; 
            if ( nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && root->m[board[nx][ny]] )
                search( board, root->m[board[nx][ny]],nx,ny,visited,res);
        }
        visited[r][c] = false;
    }
};