/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 *
 * https://leetcode.com/problems/reorder-data-in-log-files/description/
 *
 * algorithms
 * Easy (54.07%)
 * Likes:    309
 * Dislikes: 930
 * Total Accepted:    58.6K
 * Total Submissions: 108.4K
 * Testcase Example:  '["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]'
 *
 * You have an array of logs.  Each log is a space delimited string of words.
 * 
 * For each log, the first word in each log is an alphanumeric identifier.
 * Then, either:
 * 
 * 
 * Each word after the identifier will consist only of lowercase letters,
 * or;
 * Each word after the identifier will consist only of digits.
 * 
 * 
 * We will call these two varieties of logs letter-logs and digit-logs.  It is
 * guaranteed that each log has at least one word after its identifier.
 * 
 * Reorder the logs so that all of the letter-logs come before any digit-log.
 * The letter-logs are ordered lexicographically ignoring identifier, with the
 * identifier used in case of ties.  The digit-logs should be put in their
 * original order.
 * 
 * Return the final order of the logs.
 * 
 * 
 * Example 1:
 * Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit
 * dig","let3 art zero"]
 * Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5
 * 1","dig2 3 6"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * logs[i] is guaranteed to have an identifier, and a word after the
 * identifier.
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
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter_logs, digit_logs;
        for (string &s : logs) {
            auto it_at_space = find(s.cbegin(), s.cend(), ' ');
            if (isalpha(*(it_at_space + 1))) {
                letter_logs.push_back(s);
            } else {
                digit_logs.push_back(s);
            }
        }
        sort(letter_logs.begin(), letter_logs.end(),
            [] (const string &s1, const string &s2) -> bool {
                auto it_aft_space_1 = find(s1.cbegin(), s1.cend(), ' ') + 1;
                auto it_aft_space_2 = find(s2.cbegin(), s2.cend(), ' ') + 1;
                string sub1(it_aft_space_1, s1.end());
                string sub2(it_aft_space_2, s2.end());
                if (sub1 != sub2) {
                    return sub1 < sub2;
                } else { // compare identifier
                    return string(s1.begin(), it_aft_space_1) < string(s2.begin(), it_aft_space_2);
                }
        });
        letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());
        return letter_logs;
    }
};
// @lc code=end

