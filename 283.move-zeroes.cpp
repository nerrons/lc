/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (55.47%)
 * Likes:    2493
 * Dislikes: 90
 * Total Accepted:    551.6K
 * Total Submissions: 994.2K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zeros = count(nums.begin(), nums.end(), 0);
        int nonzeros = n - zeros;
        int nonzero_index = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[nonzero_index] = nums[i];
                nonzero_index++;
            }
        }
        for (int i = nonzeros; i < n; i++) {
            nums[i] = 0;
        }
    }
};
// @lc code=end

