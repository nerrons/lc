/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 *
 * https://leetcode.com/problems/monotonic-array/description/
 *
 * algorithms
 * Easy (56.20%)
 * Likes:    377
 * Dislikes: 31
 * Total Accepted:    64.5K
 * Total Submissions: 114.7K
 * Testcase Example:  '[1,2,2,3]'
 *
 * An array is monotonic if it is either monotone increasing or monotone
 * decreasing.
 * 
 * An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array
 * A is monotone decreasing if for all i <= j, A[i] >= A[j].
 * 
 * Return true if and only if the given array A is monotonic.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,2,3]
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [6,5,4,4]
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,2]
 * Output: false
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,2,4,5]
 * Output: true
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: [1,1,1]
 * Output: true
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 50000
 * -100000 <= A[i] <= 100000
 * 
 * 
 * 
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
using namespace std;
// @lc code=start
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool mono_incr = true;
        bool mono_decr = true;
        for (int i = 1; i < n; i++) {
            mono_incr &= (A[i] >= A[i - 1]);
            mono_decr &= (A[i] <= A[i - 1]);
        }
        return mono_incr || mono_decr;
    }
};
// @lc code=end

// cool one-liner
// return is_sorted( A.cbegin(), A.cend() )  ||  is_sorted( A.crbegin(), A.crend() );