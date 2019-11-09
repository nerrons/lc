/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 *
 * https://leetcode.com/problems/unique-email-addresses/description/
 *
 * algorithms
 * Easy (68.44%)
 * Likes:    591
 * Dislikes: 162
 * Total Accepted:    155.7K
 * Total Submissions: 227.7K
 * Testcase Example:  '["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]'
 *
 * Every email consists of a local name and a domain name, separated by the @
 * sign.
 * 
 * For example, in alice@leetcode.com, alice is the local name, and
 * leetcode.com is the domain name.
 * 
 * Besides lowercase letters, these emails may contain '.'s or '+'s.
 * 
 * If you add periods ('.') between some characters in the local name part of
 * an email address, mail sent there will be forwarded to the same address
 * without dots in the local name.  For example, "alice.z@leetcode.com" and
 * "alicez@leetcode.com" forward to the same email address.  (Note that this
 * rule does not apply for domain names.)
 * 
 * If you add a plus ('+') in the local name, everything after the first plus
 * sign will be ignored. This allows certain emails to be filtered, for example
 * m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule
 * does not apply for domain names.)
 * 
 * It is possible to use both of these rules at the same time.
 * 
 * Given a list of emails, we send one email to each address in the list.  How
 * many different addresses actually receive mails? 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
 * Output: 2
 * Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually
 * receive mails
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= emails[i].length <= 100
 * 1 <= emails.length <= 100
 * Each emails[i] contains exactly one '@' character.
 * All local and domain names are non-empty.
 * Local names do not start with a '+' character.
 * 
 * 
 * 
 */
#include<vector>
#include<string>
#include<iostream>
#include<numeric>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
using namespace std;
// @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> S;
        for (string &e : emails) {
            string real;

            // get the end of the useful local address
            auto it = find_if(e.begin(), e.end(),
                [](char c) -> bool { return '+' == c || '@' == c; });
            
            // copy all non-. chars to real
            copy_if(e.begin(), it, back_inserter(real),
                [](char c) -> bool { return c != '.'; });
            
            // move it to domain name and copy domain name as-is
            it = find(it, e.end(), '@');
            copy(it, e.end(), back_inserter(real));

            S.insert(real);
        }
        return S.size();
    }
};
// @lc code=end

