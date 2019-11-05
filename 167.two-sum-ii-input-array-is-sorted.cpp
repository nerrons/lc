/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (51.68%)
 * Likes:    1137
 * Dislikes: 464
 * Total Accepted:    304.9K
 * Total Submissions: 589.7K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2.
 * 
 * Note:
 * 
 * 
 * Your returned answers (both index1 and index2) are not zero-based.
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 */
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<numeric>
#include<cmath>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        vector<int> result(2);
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                result[0] = l + 1;
                result[1] = r + 1;
                break;
            }
            else if (sum > target) r--;
            else l++;
        }
        return result;
    }

    // vector<int> twoSumOld(vector<int>& numbers, int target) {
    //     unordered_map<int, int> m;
    //     for (int i = 0; i < numbers.size(); i++) {
    //         if (m.find(numbers[i]) != m.end()) {
    //             return { m[numbers[i]] + 1, i + 1};
    //         } else {
    //             m[target - numbers[i]] = i;
    //         }
    //     }
    //     return {0, 0};
    // }
};
// @lc code=end

