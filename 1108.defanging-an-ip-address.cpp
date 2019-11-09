/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 *
 * https://leetcode.com/problems/defanging-an-ip-address/description/
 *
 * algorithms
 * Easy (84.36%)
 * Likes:    142
 * Dislikes: 415
 * Total Accepted:    82.3K
 * Total Submissions: 97.3K
 * Testcase Example:  '"1.1.1.1"'
 *
 * Given a valid (IPv4) IP address, return a defanged version of that IP
 * address.
 * 
 * A defanged IP address replaces every period "." with "[.]".
 * 
 * 
 * Example 1:
 * Input: address = "1.1.1.1"
 * Output: "1[.]1[.]1[.]1"
 * Example 2:
 * Input: address = "255.100.50.0"
 * Output: "255[.]100[.]50[.]0"
 * 
 * 
 * Constraints:
 * 
 * 
 * The given address is a valid IPv4 address.
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
    string defangIPaddr(string address) {
        stringstream ss;
        for (char c : address) {
            if (c == '.') {
                ss << "[.]";
            } else {
                ss << c;
            }
        }
        return ss.str();
    }
};
// @lc code=end

