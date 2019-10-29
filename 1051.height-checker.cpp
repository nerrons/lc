/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 *
 * https://leetcode.com/problems/height-checker/description/
 *
 * algorithms
 * Easy (68.31%)
 * Likes:    96
 * Dislikes: 731
 * Total Accepted:    28K
 * Total Submissions: 40.9K
 * Testcase Example:  '[1,1,4,2,1,3]'
 *
 * Students are asked to stand in non-decreasing order of heights for an annual
 * photo.
 * 
 * Return the minimum number of students not standing in the right positions.
 * (This is the number of students that must move in order for all students to
 * be standing in non-decreasing order of height.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,1,4,2,1,3]
 * Output: 3
 * Explanation: 
 * Students with heights 4, 3 and the last 1 are not standing in the right
 * positions.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= heights.length <= 100
 * 1 <= heights[i] <= 100
 * 
 */

/* a interesting use of counting sort. */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int result = 0;
        int current_height = 0;
        vector<int> counts((size_t)101);
        for (int h : heights) {
            counts[h] += 1;
        }
        for (int i = 0; i < heights.size(); i++) {
            while (counts[current_height] == 0) {
                current_height++;
            }
            if (current_height != heights[i]) {
                result++;
            }
            counts[current_height]--;
        }
        return result;
    }
};
// @lc code=end

