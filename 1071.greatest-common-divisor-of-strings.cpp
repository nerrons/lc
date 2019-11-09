// CHEATED
/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 *
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (53.93%)
 * Likes:    195
 * Dislikes: 61
 * Total Accepted:    14.2K
 * Total Submissions: 26.4K
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T
 * concatenated with itself 1 or more times)
 * 
 * Return the largest string X such that X divides str1 and X divides str2.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "ABCABC", str2 = "ABC"
 * Output: "ABC"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: str1 = "LEET", str2 = "CODE"
 * Output: ""
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= str1.length <= 1000
 * 1 <= str2.length <= 1000
 * str1[i] and str2[i] are English uppercase letters.
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
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)
            ? str1.substr(0, gcd(str1.size(), str2.size()))
            : "";
    }
};
// @lc code=end

// This is fucking amazing