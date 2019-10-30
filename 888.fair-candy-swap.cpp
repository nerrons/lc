/*
 * @lc app=leetcode id=888 lang=cpp
 *
 * [888] Fair Candy Swap
 *
 * https://leetcode.com/problems/fair-candy-swap/description/
 *
 * algorithms
 * Easy (56.87%)
 * Likes:    368
 * Dislikes: 93
 * Total Accepted:    35.8K
 * Total Submissions: 63K
 * Testcase Example:  '[1,1]\n[2,2]'
 *
 * Alice and Bob have candy bars of different sizes: A[i] is the size of the
 * i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of
 * candy that Bob has.
 * 
 * Since they are friends, they would like to exchange one candy bar each so
 * that after the exchange, they both have the same total amount of candy.
 * (The total amount of candy a person has is the sum of the sizes of candy
 * bars they have.)
 * 
 * Return an integer array ans where ans[0] is the size of the candy bar that
 * Alice must exchange, and ans[1] is the size of the candy bar that Bob must
 * exchange.
 * 
 * If there are multiple answers, you may return any one of them.  It is
 * guaranteed an answer exists.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,1], B = [2,2]
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [1,2], B = [2,3]
 * Output: [1,2]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = [2], B = [1,3]
 * Output: [2,3]
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = [1,2,5], B = [2,4]
 * Output: [5,4]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * 1 <= B.length <= 10000
 * 1 <= A[i] <= 100000
 * 1 <= B[i] <= 100000
 * It is guaranteed that Alice and Bob have different total amounts of
 * candy.
 * It is guaranteed there exists an answer.
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
#include<unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int size_a = A.size(), size_b = B.size();
        int sum_a = accumulate(A.begin(), A.end(), 0);
        int sum_b = accumulate(B.begin(), B.end(), 0);
        int diff = (sum_a - sum_b) / 2;
        unordered_set<int> S(A.begin(), A.end());
        for (int b : B) {
            if (S.count(b + diff)) {
                return { b + diff, b };
            }
        }
        return { 0, 0 };
    }
};
// @lc code=end

// This guy is using a bitfield. actually fucking insane
// https://leetcode.com/problems/fair-candy-swap/discuss/209748/C%2B%2B-24-ms-99-O(n)-solution-using-bitfield
/*
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        
        bitset<200002> bf;
        
        int sumA = 0, sumB = 0;
        for(auto n: A) {
            sumA += n;
        }
        for(auto n: B) {
            sumB += n;
            bf.set(2*n);
        }
        
        int diff = sumA - sumB;
        
        for(auto n: A) {
            int det = 2*n - diff;
            if(det > 0 && det < 200002 && bf.test(det)) {
                return {n, (2*n-diff)/2};
            }
        }
        return {};
    }
};

auto gucciGang = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
*/