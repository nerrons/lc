/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (65.83%)
 * Likes:    460
 * Dislikes: 57
 * Total Accepted:    42K
 * Total Submissions: 63.8K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given an array A of strings made only from lowercase letters, return a list
 * of all characters that show up in all strings within the list (including
 * duplicates).  For example, if a character occurs 3 times in all strings but
 * not 4 times, you need to include that character three times in the final
 * answer.
 * 
 * You may return the answer in any order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["bella","label","roller"]
 * Output: ["e","l","l"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["cool","lock","cook"]
 * Output: ["c","o"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] is a lowercase letter
 * 
 * 
 * 
 */
#include<vector>
#include<map>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        size_t n = A.size();
        vector<int> min_counts(26, INT_MAX);
        vector<string> result;

        for (int w = 0; w < n; w++) {
            vector<int> char_counts(26);
            for (char const &c : A[w]) {
                char_counts[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                min_counts[i] = min(min_counts[i], char_counts[i]);
            }
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < min_counts[i]; j++) {
                result.push_back(string(1, i + 'a'));
            }
        }
        return result;
    }
};
// @lc code=end

