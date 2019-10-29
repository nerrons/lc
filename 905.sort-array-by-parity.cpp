/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (72.92%)
 * Likes:    593
 * Dislikes: 62
 * Total Accepted:    137.2K
 * Total Submissions: 188.1K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 * 
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        vector<int> result;
        vector<int> evens;
        vector<int> odds;
        result.reserve(n);
        for (auto &x : A) {
            if (x % 2 == 0) {
                evens.push_back(x);
            } else {
                odds.push_back(x);
            }
        }
        result.insert(result.end(), evens.begin(), evens.end());
        result.insert(result.end(), odds.begin(), odds.end());
        return result;
    }
};
// @lc code=end

