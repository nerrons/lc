/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (51.89%)
 * Likes:    617
 * Dislikes: 547
 * Total Accepted:    62.5K
 * Total Submissions: 120.4K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 * 
 * Example 1:
 * 
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation: 
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 * 
 * 
 * 
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 * 
 */
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<numeric>
#include<cmath>
#include<tuple>
using namespace std;
// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        enum { FREQ, FIRST_INDEX, LAST_INDEX };
        int n = nums.size();
        map<int, vector<int>> wc; // elem -> [freq, first_index, last_index]
        for (int i = 0; i < n; i++) {
            if (wc.find(nums[i]) == wc.end()) {
                wc[nums[i]] = vector<int>(3);
                wc[nums[i]][FREQ] = 1;
                wc[nums[i]][FIRST_INDEX] = i;
            } else {
                wc[nums[i]][FREQ]++;
            }
            wc[nums[i]][LAST_INDEX] = i;
        }
        int max_freq = 0;
        vector<int> max_elems;
        for (auto &it : wc) {
            if (it.second[FREQ] == max_freq) {
                max_elems.push_back(it.first);
            } else if (it.second[FREQ] > max_freq) {
                max_freq = it.second[FREQ];
                max_elems.clear();
                max_elems.push_back(it.first);
            }
        }

        vector<int> lengths;
        for (int i = 0; i < max_elems.size(); i++) {
            auto &info = wc[max_elems[i]];
            lengths.push_back(info[LAST_INDEX] - info[FIRST_INDEX] + 1);
        }
        return *min_element(lengths.begin(), lengths.end());
    }
};
// @lc code=end

