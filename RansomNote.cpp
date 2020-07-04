// Problem Description
/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

*/

// we use two hashmap to store the char sets of both of them 

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if ( ransomNote.size() > magazine.size() )
            return false;
        unordered_map<char,int> note_m;
        unordered_map<char,int> magazine_m;
        for ( auto ch : ransomNote )
        {
            note_m[ch]++;
        }
        for ( auto ch : magazine )
            magazine_m[ch]++;
        for ( auto it = note_m.begin(); it != note_m.end(); it++ )
        {
            if ( magazine_m.find(it->first) == magazine_m.end() || magazine_m.find(it->first)->second < it->second )
                return false;        
        }
        
        return true;
    }
};

// Can also use one hashmap 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if ( ransomNote.size() > magazine.size() )
            return false;
        unordered_map<char,int> magazine_m;

        for ( auto ch : magazine )
            magazine_m[ch]++;
        for ( auto ch : ransomNote )
        {
            if ( --magazine_m[ch] < 0 )
                return false;
        }
        
        return true;
    }
};