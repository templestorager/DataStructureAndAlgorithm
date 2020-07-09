// Problem Description
/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

class TrieNode {
public:
    TrieNode *childen[26];
    bool isWord;
    TrieNode() : isWord(false) {
        for ( auto &a : childen )
            a = nullptr;
    }
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for ( auto &a : word )
        {
            int idx = a - 'a';
            if ( !p->childen[idx] )
                p->childen[idx] = new TrieNode();
            p = p->childen[idx];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for ( auto &a : word )
        {
            int idx = a - 'a';
            if ( p->childen[idx] == nullptr )
                return false;
            p = p->childen[idx];
        }
        
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for ( auto &a : prefix )
        {
            int idx = a - 'a';
            if ( p->childen[idx] == nullptr )
                return false;
            p = p->childen[idx];
        }
        
        return true;
    }
private:
    TrieNode *root;
};