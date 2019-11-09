/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 *
 * https://leetcode.com/problems/remove-outermost-parentheses/description/
 *
 * algorithms
 * Easy (75.45%)
 * Likes:    243
 * Dislikes: 367
 * Total Accepted:    54.1K
 * Total Submissions: 71.6K
 * Testcase Example:  '"(()())(())"'
 *
 * A valid parentheses string is either empty (""), "(" + A + ")", or A + B,
 * where A and B are valid parentheses strings, and + represents string
 * concatenation.  For example, "", "()", "(())()", and "(()(()))" are all
 * valid parentheses strings.
 * 
 * A valid parentheses string S is primitive if it is nonempty, and there does
 * not exist a way to split it into S = A+B, with A and B nonempty valid
 * parentheses strings.
 * 
 * Given a valid parentheses string S, consider its primitive decomposition: S
 * = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.
 * 
 * Return S after removing the outermost parentheses of every primitive string
 * in the primitive decomposition of S.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "(()())(())"
 * Output: "()()()"
 * Explanation: 
 * The input string is "(()())(())", with primitive decomposition "(()())" +
 * "(())".
 * After removing outer parentheses of each part, this is "()()" + "()" =
 * "()()()".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "(()())(())(()(()))"
 * Output: "()()()()(())"
 * Explanation: 
 * The input string is "(()())(())(()(()))", with primitive decomposition
 * "(()())" + "(())" + "(()(()))".
 * After removing outer parentheses of each part, this is "()()" + "()" +
 * "()(())" = "()()()()(())".
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "()()"
 * Output: ""
 * Explanation: 
 * The input string is "()()", with primitive decomposition "()" + "()".
 * After removing outer parentheses of each part, this is "" + "" = "".
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S.length <= 10000
 * S[i] is "(" or ")"
 * S is a valid parentheses string
 * 
 * 
 * 
 * 
 * 
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
    string removeOuterParentheses(string S) {
        string result = "";
        int count = 0;
        for (char &c : S) {
            if (c == '(') {
                count++;
                if (count > 1) {
                    result += '(';
                }
            } else {
                count--;
                if (count > 0) {
                    result += ')';
                }
            }
        }
        return result;
    }
};
// @lc code=end

// a stupid solution that uses 4 pointers
/*
class Solution {
public:
    string removeOuterParentheses(string S) {
        string result = "";
        int open = 0, close = 0;
        for (int left = 0, right = 0; right < S.size(); right++) {
            if (S[right] == '(') {
                open++;
            } else {
                close++;
            }
            if (open == close) { // found primitive
                if (open > 1) {
                    result += S.substr(left + 1, right - left - 1);
                }
                left = right + 1;
                open = 0;
                close = 0;
            }
        }
        return result;
    }
};
*/