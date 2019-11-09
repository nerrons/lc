/*
 * @lc app=leetcode id=893 lang=cpp
 *
 * [893] Groups of Special-Equivalent Strings
 *
 * https://leetcode.com/problems/groups-of-special-equivalent-strings/description/
 *
 * algorithms
 * Easy (63.84%)
 * Likes:    174
 * Dislikes: 875
 * Total Accepted:    19.3K
 * Total Submissions: 30.2K
 * Testcase Example:  '["abcd","cdab","cbad","xyzz","zzxy","zzyx"]'
 *
 * You are given an array A of strings.
 * 
 * A move onto S consists of swapping any two even indexed characters of S, or
 * any two odd indexed characters of S.
 * 
 * Two strings S and T are special-equivalent if after any number of moves onto
 * S, S == T.
 * 
 * For example, S = "zzxy" and T = "xyzz" are special-equivalent because we may
 * make the moves "zzxy" -> "xzzy" -> "xyzz" that swap S[0] and S[2], then S[1]
 * and S[3].
 * 
 * Now, a group of special-equivalent strings from A is a non-empty subset of A
 * such that:
 * 
 * 
 * Every pair of strings in the group are special equivalent, and;
 * The group is the largest size possible (ie., there isn't a string S not in
 * the group such that S is special equivalent to every string in the group)
 * 
 * 
 * Return the number of groups of special-equivalent strings from A.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["abcd","cdab","cbad","xyzz","zzxy","zzyx"]
 * Output: 3
 * Explanation: 
 * One group is ["abcd", "cdab", "cbad"], since they are all pairwise special
 * equivalent, and none of the other strings are all pairwise special
 * equivalent to these.
 * 
 * The other two groups are ["xyzz", "zzxy"] and ["zzyx"].  Note that in
 * particular, "zzxy" is not special equivalent to "zzyx".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["abc","acb","bac","bca","cab","cba"]
 * Output: 3
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[i].length <= 20
 * All A[i] have the same length.
 * All A[i] consist of only lowercase letters.
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include<vector>
#include<string>
#include<iostream>
#include<numeric>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
using namespace std;

// This all comes from discussion. It's making a signature for each string
// and counting the signatures with sets. Seems like a lot of counting wants
// sets.
// @lc code=start
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> S;
        for (const string &s : A) {
            string odd, even;
            for (int i = 0; i < s.size(); i++) {
                if (i % 2 == 0) even += s[i];
                else odd += s[i];
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            S.insert(odd + even);
        }
        return S.size();
    }
};
// @lc code=end

