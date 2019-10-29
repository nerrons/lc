/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 *
 * https://leetcode.com/problems/minimum-absolute-difference/description/
 *
 * algorithms
 * Easy (66.23%)
 * Likes:    73
 * Dislikes: 9
 * Total Accepted:    14.9K
 * Total Submissions: 22.5K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given an array of distinct integers arr, find all pairs of elements with the
 * minimum absolute difference of any two elements. 
 * 
 * Return a list of pairs in ascending order(with respect to pairs), each pair
 * [a, b] follows
 * 
 * 
 * a, b are from arr
 * a < b
 * b - a equals to the minimum absolute difference of any two elements in
 * arr
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [4,2,1,3]
 * Output: [[1,2],[2,3],[3,4]]
 * Explanation: The minimum absolute difference is 1. List all pairs with
 * difference equal to 1 in ascending order.
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,3,6,10,15]
 * Output: [[1,3]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [3,8,-10,23,19,-4,-14,27]
 * Output: [[-14,-10],[19,23],[23,27]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr.length <= 10^5
 * -10^6 <= arr[i] <= 10^6
 * 
 * 
 */

// don't need to use abs() because already sorted

#include<vector>
#include<map>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int len = arr.size();
        int min_diff = arr[1] - arr[0];

        // find min diff
        for (int i = 0; i < len - 1; i++) {
            // min is faster than manual comparing
            min_diff = min(arr[i + 1] - arr[i], min_diff);
        }

        // check if diff is min
        for (int i = 0; i < len - 1; i++) {
            if (arr[i + 1] - arr[i] == min_diff) {
                result.push_back({ arr[i], arr[i + 1] });
            };
        }
        return result;
    }
};
// @lc code=end

