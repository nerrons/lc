/*
 * @lc app=leetcode id=999 lang=cpp
 *
 * [999] Available Captures for Rook
 *
 * https://leetcode.com/problems/available-captures-for-rook/description/
 *
 * algorithms
 * Easy (65.75%)
 * Likes:    120
 * Dislikes: 278
 * Total Accepted:    19.8K
 * Total Submissions: 30.1K
 * Testcase Example:  '[[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]'
 *
 * On an 8 x 8 chessboard, there is one white rook.  There also may be empty
 * squares, white bishops, and black pawns.  These are given as characters 'R',
 * '.', 'B', and 'p' respectively. Uppercase characters represent white pieces,
 * and lowercase characters represent black pieces.
 * 
 * The rook moves as in the rules of Chess: it chooses one of four cardinal
 * directions (north, east, west, and south), then moves in that direction
 * until it chooses to stop, reaches the edge of the board, or captures an
 * opposite colored pawn by moving to the same square it occupies.  Also, rooks
 * cannot move into the same square as other friendly bishops.
 * 
 * Return the number of pawns the rook can capture in one move.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input:
 * [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
 * Output: 3
 * Explanation: 
 * In this example the rook is able to capture all the pawns.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input:
 * [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
 * Output: 0
 * Explanation: 
 * Bishops are blocking the rook to capture any pawn.
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input:
 * [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
 * Output: 3
 * Explanation: 
 * The rook can capture the pawns at positions b5, d6 and f5.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * board.length == board[i].length == 8
 * board[i][j] is either 'R', '.', 'B', or 'p'
 * There is exactly one cell with board[i][j] == 'R'
 * 
 * 
 */
#include<vector>
#include<map>
#include<string>
#include<tuple>
using namespace std;
// @lc code=start
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        // find rook
        pair<int, int> rook;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    rook = { i, j };
                    break;
                }
            }
        }

        int row = rook.first;
        int col = rook.second;
        vector<int> eat = { 0, 0, 0, 0 };

        // west
        if (col > 0) {
            char dest;
            for (int i = col - 1; i >= 0; i--) {
                dest = board[row][i];
                if (dest == 'B') break;
                if (dest == 'p') {
                    eat[0]++;
                    break;
                }
            }
        }

        // east
        if (col < 7) {
            char dest;
            for (int i = col + 1; i < 8; i++) {
                dest = board[row][i];
                if (dest == 'B') break;
                if (dest == 'p') {
                    eat[1]++;
                    break;
                }
            }
        }

        // north
        if (row > 0) {
            char dest;
            for (int i = row - 1; i >= 0; i--) {
                dest = board[i][col];
                if (dest == 'B') break;
                if (dest == 'p') {
                    eat[2]++;
                    break;
                }
            }
        }

        // south
        if (row < 7) {
            char dest;
            for (int i = row + 1; i < 8; i++) {
                dest = board[i][col];
                if (dest == 'B') break;
                if (dest == 'p') {
                    eat[3]++;
                    break;
                }
            }
        }

        return (eat[0] + eat[1] + eat[2] + eat[3]);
    }
};
// @lc code=end

