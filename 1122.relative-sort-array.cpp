/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 *
 * https://leetcode.com/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (66.21%)
 * Likes:    260
 * Dislikes: 18
 * Total Accepted:    26.3K
 * Total Submissions: 39.7K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all
 * elements in arr2 are also in arr1.
 * 
 * Sort the elements of arr1 such that the relative ordering of items in arr1
 * are the same as in arr2.  Elements that don't appear in arr2 should be
 * placed at the end of arr1 in ascending order.
 * 
 * 
 * Example 1:
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 * 
 * 
 * Constraints:
 * 
 * 
 * arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * Each arr2[i] is distinct.
 * Each arr2[i] is in arr1.
 * 
 * 
 */
#include<vector>
#include<map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        map<int, int> counts;
        int sorted = 0;
        for (int const &i : arr1) {
            if (counts.find(i) == counts.end()) {
                counts[i] = 1;
            } else {
                counts[i]++;
            }
        }
        for (int const &i : arr2) {
            int count = counts[i];
            for (int j = 0; j < count; j++) {
                result.push_back(i);
                counts[i]--;
                sorted++;
            }
        }
        for (auto const &it : counts) {
            int n = it.second;
            while (n != 0) {
                result.push_back(it.first);
                n--;
            }
        }
        sort((result.begin() + sorted), result.end());
        return result;
    }
};
// @lc code=end

