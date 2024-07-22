/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (74.19%)
 * Likes:    1670
 * Dislikes: 0
 * Total Accepted:    287.4K
 * Total Submissions: 387.3K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 * 
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 
 * 
 * 
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[["Q"]]
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
            res.push_back(currSol);
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

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        aSolution({}, 0, n);
        return res;
    }

public:
    std::vector<std::vector<std::string>> res;
};
// @lc code=end

int main() {
    Solution s;
    s.solveNQueens(4);

    return 0;
}
