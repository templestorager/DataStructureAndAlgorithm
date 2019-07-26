// Problem Description 
/*
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of 
 * shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
    Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.
    Example 1:

    Input:
    beginWord = "hit",
    endWord = "cog",
    wordList = ["hot","dot","dog","lot","log","cog"]

    Output: 5

    Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
    return its length 5.
    Example 2:

    Input:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log"]

    Output: 0

    Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

 * 
 */

// Uses BFS to check every possible next word for each existing word on the path 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if ( !wordSet.count(endWord) ) 
            return 0;
        unordered_map<string, int> pathCnt{{beginWord,1}};
        queue<string> q{{beginWord}};
        while( !q.empty() ) {
            string word = q.front();
            q.pop();
            for ( int i = 0; i < word.size(); i++ ) {
                string nextword = word;
                for ( char ch = 'a'; ch <= 'z'; ch++ ) {
                    if ( ch == nextword[i] ) {
                        continue;
                    }
                    else 
                    {
                        nextword[i] = ch;
                    }
                    
                    if ( wordSet.count(nextword) && nextword == endWord ) 
                        return pathCnt[word] + 1;
                    if  (wordSet.count(nextword) && !pathCnt.count(nextword) ) {
                        q.push(nextword);
                        pathCnt[nextword] = pathCnt[word] + 1;
                    }
                }
            }
        }
        return 0;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(),wordList.end());
        if ( !wordset.count(endWord) ) 
            return 0;
        queue<string> q{{beginWord}};
        int res = 0;
        while ( !q.empty() ) {
            for ( int k = q.size(); k > 0; k-- ) {
                string currentword = q.front();
                q.pop();
                if ( currentword == endWord ) 
                    return res+1;
                for ( int i = 0; i < currentword.size(); i++ ) {
                    string nextword = currentword;
                    for ( char ch = 'a'; ch <= 'z'; ++ch ) {
                        if ( nextword[i] == ch ) {
                            continue;
                        }
                        else {
                            nextword[i] = ch;
                            if ( wordset.count(nextword) && nextword != currentword ) {
                                q.push(nextword);
                                wordset.erase(nextword);
                            }
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};

// *********************************************
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int strlen = beginWord.size();
        unordered_map<string, vector<string>> wordDictMap;
        for ( int i = 0; i < wordList.size(); i++ ) {
            for  ( int j = 0; j < strlen; j++ ) {
                string genericword = wordList[i].substr(0,j)+"*"+wordList[i].substr(j+1);
                wordDictMap[genericword].push_back(wordList[i]);
            }
        }
        queue<make_pair<string,int> > q{make_pair(beginWord,1)};
        unordered_map<string, bool> visisted{{beginWord,true}};
        while ( !q.empty() ) {
            auto entry = q.front();
            q.pop();
            string currentword = entry.first();
            int level = entry.second();
            for ( int k = 0; k < strlen; k++ ) {
                string nextword = currentword.substr(0,k) + "*" + currentword.substr(k+1);
                for ( string word : wordDickMap[nextword] ) {
                    if ( word == endWord ) { 
                        return level + 1;
                    }
                    
                    if ( !visited.count(word) ) {
                        visited.insert({word,true});
                        q.insert({word,level+1});
                    }
                }
            }
        }
        return 0;
    }
};