// Problem Description
/*
    Every email consists of a local name and a domain name, separated by the @ sign.

    For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

    Besides lowercase letters, these emails may contain '.'s or '+'s.

    If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

    If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

    It is possible to use both of these rules at the same time.

    Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 

    

    Example 1:

    Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
    Output: 2
    Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
    

    Note:

    1 <= emails[i].length <= 100
    1 <= emails.length <= 100
    Each emails[i] contains exactly one '@' character.
    All local and domain names are non-empty.
    Local names do not start with a '+' character.
 *
 */

// Straightfoward method. 
// For each email address, it tries to find process it in two part divided by '@' 

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueemails;
        for ( int i = 0; i < emails.size(); i++ ) {
            string temp; 
            for ( int j = 0; j < emails[i].size(); j++ ) {
                if ( emails[i][j] == '+' ) {
                    while ( emails[i][j] != '@' ) 
                        j++;
                    temp += emails[i].substr( j, emails[i].size()-j );
                    uniqueemails.insert(temp);
                    break;
                } else if ( emails[i][j] == '.' ) {
                    continue;
                } else if ( emails[i][j] == '@' ) {
                    temp += emails[i].substr(j, emails[i].size() - j );
                    uniqueemails.insert(temp);
                    break;
                }
                else { 
                    temp += emails[i][j];
                }
            }
            
            uniqueemails.insert(temp);
        }
        
        return uniqueemails.size();
    }
};



class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueemails;
        for ( int i = 0; i < emails.size(); i++ ) {
            int atpos = emails[i].find('@');
            string local = emails[i].substr(0,atpos);
            string domain = emails[i].substr(atpos+1,emails[i].size()-atpos-1);
            size_t pluspos = local.find_first_of('+');
            if ( pluspos != string::npos ) {
                local = local.substr(0,pluspos);
            }
            string strnodot;
            for ( int j = 0; j < local.size(); j++ ) {
                if ( local[j] != '.' ) 
                    strnodot += local[j];
            }
            
            uniqueemails.insert(strnodot+"@"+domain);
        }
        
        return uniqueemails.size();
    }
};