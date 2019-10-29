/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 *
 * https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/
 *
 * algorithms
 * Easy (66.78%)
 * Likes:    119
 * Dislikes: 31
 * Total Accepted:    20.5K
 * Total Submissions: 30.7K
 * Testcase Example:  '["cat","bt","hat","tree"]\n"atach"\n["hello","world","leetcode"]\n"welldonehoneyr"'
 *
 * You are given an array of strings words and a string chars.
 * 
 * A string is good if it can be formed by characters from chars (each
 * character can only be used once).
 * 
 * Return the sum of lengths of all good strings in words.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["cat","bt","hat","tree"], chars = "atach"
 * Output: 6
 * Explanation: 
 * The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 =
 * 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
 * Output: 10
 * Explanation: 
 * The strings that can be formed are "hello" and "world" so the answer is 5 +
 * 5 = 10.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length, chars.length <= 100
 * All strings contain lowercase English letters only.
 * 
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> chars_count((size_t)26);
        for (auto &c : chars) {
            chars_count[c - 'a'] += 1;
        }
        int sum = 0;
        for (auto &word : words) {
            bool good = true;
            vector<int> wc((size_t)26);
            for (auto &c : word) {
                int index = c - 'a';
                wc[index] += 1;
                if (wc[index] > chars_count[index]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                sum += word.size();
            }
        }
        return sum;
    }
};
// @lc code=end

