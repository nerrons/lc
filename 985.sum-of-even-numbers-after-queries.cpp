/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
 *
 * https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/
 *
 * algorithms
 * Easy (62.30%)
 * Likes:    216
 * Dislikes: 96
 * Total Accepted:    29.8K
 * Total Submissions: 47.9K
 * Testcase Example:  '[1,2,3,4]\n[[1,0],[-3,1],[-4,0],[2,3]]'
 *
 * We have an array A of integers, and an array queries of queries.
 * 
 * For the i-th query val = queries[i][0], index = queries[i][1], we add val to
 * A[index].  Then, the answer to the i-th query is the sum of the even values
 * of A.
 * 
 * (Here, the given index = queries[i][1] is a 0-based index, and each query
 * permanently modifies the array A.)
 * 
 * Return the answer to all queries.  Your answer array should have answer[i]
 * as the answer to the i-th query.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
 * Output: [8,6,2,4]
 * Explanation: 
 * At the beginning, the array is [1,2,3,4].
 * After adding 1 to A[0], the array is [2,2,3,4], and the sum of even values
 * is 2 + 2 + 4 = 8.
 * After adding -3 to A[1], the array is [2,-1,3,4], and the sum of even values
 * is 2 + 4 = 6.
 * After adding -4 to A[0], the array is [-2,-1,3,4], and the sum of even
 * values is -2 + 4 = 2.
 * After adding 2 to A[3], the array is [-2,-1,3,6], and the sum of even values
 * is -2 + 6 = 4.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * 1 <= queries.length <= 10000
 * -10000 <= queries[i][0] <= 10000
 * 0 <= queries[i][1] < A.length
 * 
 * 
 */
#include<vector>
#include<map>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int oldval, newval, index;
        int sum = 0;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0) sum += A[i];
        }

        int n = queries.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            index = queries[i][1];
            oldval = A[index];
            A[index] += queries[i][0];
            newval = A[index];
            // using !(x % 2) is significantly slower than using (x % 2 == 0)
            // TODO: check out why
            if (oldval % 2 == 0) {
                sum -= oldval;
            }
            if (newval % 2 == 0) {
                sum += newval;
            }
            result[i] = sum;
        }
        return result;
    }
};
// @lc code=end
