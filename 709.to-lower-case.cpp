/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (77.87%)
 * Likes:    347
 * Dislikes: 1209
 * Total Accepted:    158K
 * Total Submissions: 202.7K
 * Testcase Example:  '"Hello"'
 *
 * Implement function ToLowerCase() that has a string parameter str, and
 * returns the same string in lowercase.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "Hello"
 * Output: "hello"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "here"
 * Output: "here"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "LOVELY"
 * Output: "lovely"
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
    string toLowerCase(string str) {
        string result;
        int dist = 'Z' - 'z';
        for (char &c : str) {
            if (c >= 'A' && c <= 'Z') {
                result += c - dist;
            } else {
                result += c;
            }
        }
        return result;
    }
};
// @lc code=end

