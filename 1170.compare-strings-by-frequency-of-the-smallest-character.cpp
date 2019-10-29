/*
 * @lc app=leetcode id=1170 lang=cpp
 *
 * [1170] Compare Strings by Frequency of the Smallest Character
 *
 * https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/
 *
 * algorithms
 * Easy (58.92%)
 * Likes:    72
 * Dislikes: 183
 * Total Accepted:    15.4K
 * Total Submissions: 26.1K
 * Testcase Example:  '["cbd"]\n["zaaaz"]'
 *
 * Let's define a function f(s) over a non-empty string s, which calculates the
 * frequency of the smallest character in s. For example, if s = "dcce" then
 * f(s) = 2 because the smallest character is "c" and its frequency is 2.
 * 
 * Now, given string arrays queries and words, return an integer array answer,
 * where each answer[i] is the number of words such that f(queries[i]) < f(W),
 * where W is a word in words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: queries = ["cbd"], words = ["zaaaz"]
 * Output: [1]
 * Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so
 * f("cbd") < f("zaaaz").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
 * Output: [1,2]
 * Explanation: On the first query only f("bbb") < f("aaaa"). On the second
 * query both f("aaa") and f("aaaa") are both > f("cc").
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= queries.length <= 2000
 * 1 <= words.length <= 2000
 * 1 <= queries[i].length, words[i].length <= 10
 * queries[i][j], words[i][j] are English lowercase letters.
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
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int num_words = words.size();
        int num_queries = queries.size();
        vector<int> word_scores(num_words);
        vector<int> result(num_queries);
        map<int, int> cache;
        for (int w = 0; w < num_words; w++) {
            word_scores[w] = calcScore(words[w]);
        }
        for (int q = 0; q < num_queries; q++) {
            int score = calcScore(queries[q]);
            if (cache.find(score) != cache.end()) {
                result[q] = cache[score];
            } else {
                for (int w = 0; w < num_words; w++) {
                    if (score < word_scores[w]) {
                        result[q]++;
                    }
                }
                cache[score] = result[q];
            }
        }
        return result;
    }
    int calcScore(string &word) {
        char min_char = 'z' + 1;
        int score = 0;
        for (auto &c : word) {
            if (c < min_char) {
                min_char = c;
                score = 1;
            } else if (c == min_char) {
                score++;
            }
        }
        return score;
    }
};
// @lc code=end

