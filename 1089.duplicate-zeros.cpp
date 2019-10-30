/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 *
 * https://leetcode.com/problems/duplicate-zeros/description/
 *
 * algorithms
 * Easy (58.56%)
 * Likes:    179
 * Dislikes: 118
 * Total Accepted:    21.7K
 * Total Submissions: 37.1K
 * Testcase Example:  '[1,0,2,3,0,4,5,0]'
 *
 * Given a fixed length array arr of integers, duplicate each occurrence of
 * zero, shifting the remaining elements to the right.
 * 
 * Note that elements beyond the length of the original array are not written.
 * 
 * Do the above modifications to the input array in place, do not return
 * anything from your function.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,2,3,0,4,5,0]
 * Output: null
 * Explanation: After calling your function, the input array is modified to:
 * [1,0,0,2,3,0,0,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3]
 * Output: null
 * Explanation: After calling your function, the input array is modified to:
 * [1,2,3]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= arr.length <= 10000
 * 0 <= arr[i] <= 9
 * 
 */

// despite all the downvotes, this is actually a nice practice on edge cases.

#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeros = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) zeros++;
        }
        if (zeros == 0) return;
        int j = n - 1 + zeros;
        // might be easier to understand if visualize
        // it's like writing the new array to a black hole following
        // the old array -- all the values past the last element
        // will be written to the void
        for (int i = n - 1; i >= 0; i--) {
            if (j < n) {
                arr[j] = arr[i];
            }
            if (arr[i] == 0) {
                j--;
                if (j < n) {
                    arr[j] = 0;
                }
            }
            j--;
        }
    }
};
// @lc code=end

