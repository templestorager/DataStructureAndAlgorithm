// Problem Description
/*
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

 

Example 1:

Input: dict = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
 

Constraints:

The input will only have lower-case letters.
1 <= dict.length <= 1000
1 <= dict[i].length <= 100
1 <= sentence words number <= 1000
1 <= sentence words length <= 1000
*/

// This is a navie solution that maintains all prefixes starting with the same char to a vector, 
// and the strings are sorted according to their lens.
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string res, tmp = "";
        vector<vector<string>> prefix(26);
        istringstream is(sentence);
        sort( dict.begin(),dict.end(),[](string &a, string &b){ return a.size() < b.size();});
        for ( string w : dict )
        {
            prefix[w[0]-'a'].push_back(w);
        }
        
        while ( is >> tmp )
        {
            for ( string w : prefix[tmp[0]-'a'] )
            {
                if ( tmp.substr(0,w.size()) == w )
                {
                    tmp = w;
                    break;
                }
            }
            res += tmp + " ";
        }
        res.pop_back();
        return res;
    }
};

// This solution uses the trie structure
class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> m;
    TrieNode() :isWord(false) {m.clear();}
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string res, tmp = "", candidate = "";
        for ( auto &d : dict )
            InsertWord(d);
        istringstream is(sentence);
        while ( is >> tmp )
        {
            for(int i = 1; i <= tmp.size(); i++ )
            {
                candidate = tmp.substr(0,i);
                if ( CheckPrefix(candidate) )
                {
                    break;
                }
            }
            res += candidate + " ";
        }
        
        res.pop_back();
        return res;
    }
private:
    TrieNode *root = nullptr;
    void InsertWord( const string word )
    {
        if ( root == nullptr )
            root = new TrieNode();
        TrieNode *p = root;
        for ( auto &a : word )
        {
            if ( p->m[a] == nullptr )
            {
                p->m[a] = new TrieNode();
            }
            p = p->m[a]; 
        }
        p->isWord = true;
    }
    
    bool CheckPrefix( const string prefix )
    {
        TrieNode *p = root;
        for ( auto &a : prefix )
        {
            if ( p->m[a] == nullptr )
                return false;
            p = p->m[a];
        }
        return p->isWord;
    }
};

// Optimize a bit 
class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> m;
    TrieNode() :isWord(false) {m.clear();}
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string res, tmp = "", candidate = "";
        for ( auto &d : dict )
            InsertWord(d);
        istringstream is(sentence);
        while ( is >> tmp )
        {
            if ( tmp.empty() )
                res += " ";
            else 
                res += FindPrefix(tmp) + " ";
        }
        
        res.pop_back();
        return res;
    }
private:
    TrieNode *root = nullptr;
    void InsertWord( const string word )
    {
        if ( root == nullptr )
            root = new TrieNode();
        TrieNode *p = root;
        for ( auto &a : word )
        {
            if ( p->m[a] == nullptr )
            {
                p->m[a] = new TrieNode();
            }
            p = p->m[a]; 
        }
        p->isWord = true;
    }
    
    string FindPrefix( const string word )
    {
        string res;
        TrieNode *p = root;
        for ( auto &a : word )
        {
            if ( p->m[a] == nullptr )
                break;
            res += a;
            if ( p->m[a]->isWord )
                return res;
            p = p->m[a];
        }
        return word;
    }
};