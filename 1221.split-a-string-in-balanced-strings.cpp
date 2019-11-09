/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 *
 * https://leetcode.com/problems/split-a-string-in-balanced-strings/description/
 *
 * algorithms
 * Easy (78.58%)
 * Likes:    102
 * Dislikes: 67
 * Total Accepted:    17.6K
 * Total Submissions: 22.6K
 * Testcase Example:  '"RLRRLLRLRL"'
 *
 * Balanced strings are those who have equal quantity of 'L' and 'R'
 * characters.
 * 
 * Given a balanced string s split it in the maximum amount of balanced
 * strings.
 * 
 * Return the maximum amount of splitted balanced strings.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "RLRRLLRLRL"
 * Output: 4
 * Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring
 * contains same number of 'L' and 'R'.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "RLLLLRRRLR"
 * Output: 3
 * Explanation: s can be split into "RL", "LLLRRR", "LR", each substring
 * contains same number of 'L' and 'R'.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "LLLLRRRR"
 * Output: 1
 * Explanation: s can be split into "LLLLRRRR".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s[i] = 'L' or 'R'
 * 
 * 
 */
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<numeric>
#include<cmath>
#include<unordered_map>
#include<sstream>
using namespace std;
// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int result = 0;
        for (char &c : s) {
            // for unknown reasons, using two ifs is faster than using if else.
            // might just be leetcode's bullshit optimization, dunno yet.
            if (c == 'L') {
                balance++;
            }
            if (c == 'R') {
                balance--;
            }
            if (balance == 0) {
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

