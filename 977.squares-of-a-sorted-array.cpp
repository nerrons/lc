/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (71.80%)
 * Likes:    555
 * Dislikes: 57
 * Total Accepted:    121K
 * Total Submissions: 168.6K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an array of integers A sorted in non-decreasing order, return an array
 * of the squares of each number, also in sorted non-decreasing order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A is sorted in non-decreasing order.
 * 
 * 
 * 
 */
#include<vector>
#include<cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> result(A.size());
        int start = 0, end = n - 1;
        int index = n - 1;
        while (start <= end) {
            int a = A[start], b = A[end];
            // no need to check if a < 0 cuz (abs(a) > b) only happens when a < 0
            if (abs(a) > b) {
                result[index] = pow(a, 2);
                index--;
                start++;
            } else {
                result[index] = pow(b, 2);
                index--;
                end--;
            }
        }
        return result;
    }
};
// @lc code=end

