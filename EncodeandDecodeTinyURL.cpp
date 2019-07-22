// Problem Description 
/* 
 * Note: This is a companion problem to the System Design problem: Design TinyURL.
 * TinyURL is a URL shortening service where you enter a URL such as 
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such as 
 * http://tinyurl.com/4e9iAk.
 * Design the encode and decode methods for the TinyURL service. There is no restriction on how 
 * your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to
 * a tiny URL and the tiny URL can be decoded to the original URL.
 * 
 */

// This solution uses the sequente number of an incoming url string to differentiate its uniqueness 
// O(1), O(n)
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        url.push_back(longUrl);
        return "http://tinyurl.com/" + to_string(url.size() - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        std::size_t pos = shortUrl.find_last_of('/');
        return url[stoi(shortUrl.substr(pos + 1))];
    }
    
private:
    vector<string> url;
};

// The above solution has the following limitations
// 1. Limited by the int range 2. Overwriting if overflow 
// 3. The encodeded url is not necessarily shorter 
// 4. Patten is predictable and can be easily detected

// This solution uses fixed length randomly generated string to encode a long string. 
class Solution {

public:
    Solution() {
        code_len = 8;
        code = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        srand(time(NULL));
        short2long.clear();
        long2short.clear();
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string randstr; 
        int len = code_len, idx = 0;
        if ( long2short.count(longUrl) ) 
            return "http://tinyurl.com/"+long2short[longUrl];
        
        while( len-- ) { 
            randstr.push_back(code[rand()%62]);
        }
        
        while ( short2long.count(randstr) ) {
            randstr[idx] = code[rand()%62];
            idx = (idx + 1) % 8;
        }
        long2short[longUrl] = randstr;
        short2long[randstr] = longUrl;
        return "http://tinyurl.com/"+randstr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string encoded_part = shortUrl.substr(shortUrl.find_last_of('/')+1);
        return short2long.count(encoded_part) ? short2long[encoded_part] : shortUrl;
    }
    
private:
    vector<string> url;
    string code;
    int code_len;
    unordered_map<string,string> short2long,long2short;
};

