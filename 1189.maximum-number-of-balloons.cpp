/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 *
 * https://leetcode.com/problems/maximum-number-of-balloons/description/
 *
 * algorithms
 * Easy (61.87%)
 * Likes:    85
 * Dislikes: 16
 * Total Accepted:    14.9K
 * Total Submissions: 24.2K
 * Testcase Example:  '"nlaebolko"'
 *
 * Given a string text, you want to use the characters of text to form as many
 * instances of the word "balloon" as possible.
 * 
 * You can use each character in text at most once. Return the maximum number
 * of instances that can be formed.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: text = "nlaebolko"
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: text = "loonbalxballpoon"
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: text = "leetcode"
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= text.length <= 10^4
 * text consists of lower case English letters only.
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
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> wc;
        for (char &c : text) {
            if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') {
                wc[c]++;
            }
        }
        vector<int> count {
            wc['b'], wc['a'], wc['l'] / 2, wc['o'] / 2, wc['n']
        };
        return *min_element(count.begin(), count.end());
    }
};
// @lc code=end

