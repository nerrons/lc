/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (65.96%)
 * Likes:    735
 * Dislikes: 74
 * Total Accepted:    155.5K
 * Total Submissions: 235.3K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
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
    string reverseWords(string s) {
        auto word_start = s.begin();
        while (word_start <= s.end() - 1) {
            auto next_space = find(word_start, s.end(), ' ');
            reverse(word_start, next_space);
            word_start = next_space + 1;
        }
        return s;
    }
};
// @lc code=end

