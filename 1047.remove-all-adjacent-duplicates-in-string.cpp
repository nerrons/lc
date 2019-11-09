/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 *
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
 *
 * algorithms
 * Easy (65.02%)
 * Likes:    326
 * Dislikes: 34
 * Total Accepted:    35.8K
 * Total Submissions: 54.9K
 * Testcase Example:  '"abbaca"'
 *
 * Given a string S of lowercase letters, a duplicate removal consists of
 * choosing two adjacent and equal letters, and removing them.
 * 
 * We repeatedly make duplicate removals on S until we no longer can.
 * 
 * Return the final string after all such duplicate removals have been made.
 * It is guaranteed the answer is unique.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abbaca"
 * Output: "ca"
 * Explanation: 
 * For example, in "abbaca" we could remove "bb" since the letters are adjacent
 * and equal, and this is the only possible move.  The result of this move is
 * that the string is "aaca", of which only "aa" is possible, so the final
 * string is "ca".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 20000
 * S consists only of English lowercase letters.
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
// This is a very clever solution: using a pointer to simulate stack.
// Using direct assignment and substr to simulate pop().
class Solution {
public:
    string removeDuplicates(string S) {
        string result = S;
        int p_res = 0;
        for (int p_s = 0; p_s < result.size(); p_s++, p_res++) {
            result[p_res] = result[p_s];
            if (p_res > 0 && result[p_res - 1] == result[p_res]) {
                p_res -= 2;
            }
        }
        return result.substr(0, p_res);
    }
};
// @lc code=end

// A naive solution I initially had
/*
class Solution {
public:
    string removeDuplicates(string S) {
        bool flag = true;
        int n = S.size();
        while (flag) {
            flag = false;
            for (int i = 0; i < n - 1; i++) {
                if (S[i] == S[i + 1]) {
                    S.erase(i, 2);
                    flag = true;
                }
            }
        }
        return S;
    }
};
*/

// from discussion, a stack version
/*
class Solution {
public:
    string removeDuplicates(string S) {
        string result = "";
        for (char &c : S) {
            if (result.size() && c == result.back()) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
*/