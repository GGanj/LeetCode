/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 *
 * https://leetcode.cn/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (82.47%)
 * Likes:    415
 * Dislikes: 0
 * Total Accepted:    114.3K
 * Total Submissions: 138.6K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：2
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 9
 * 
 * 
 * 
 * 
 */
#include <vector>
#include <string>
// @lc code=start
class Solution {
public:
    bool checked(std::vector<std::string>& currSol, int index, int position, int n) {
        for(int i = 0; i < index; ++i) {
            if(currSol[i][position] == 'Q') {
                return false;
            }
            if((position - index + i) >= 0 && currSol[i][position - index + i] == 'Q') {
                return false;
            }
            if((position + index - i) < n && currSol[i][position + index - i] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void aSolution(std::vector<std::string> currSol, int index, int n) {
        if(index == n) {
            ++totalRes;
            return;
        }
        std::string currStr;
        for(int i = 0; i < n; ++i) {
            currStr.append(".");
        }
        for(int i = 0; i < n; ++i) {
            if(checked(currSol, index, i, n)) {
                currStr[i] = 'Q';
                currSol.push_back(currStr);
                aSolution(currSol, index + 1, n);
                currSol.pop_back();
                currStr[i] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        aSolution({}, 0, n);
        return totalRes;
    }
public:
    int totalRes = 0;
};
// @lc code=end

