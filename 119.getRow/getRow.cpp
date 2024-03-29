/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (68.19%)
 * Likes:    398
 * Dislikes: 0
 * Total Accepted:    203.5K
 * Total Submissions: 297.6K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
 * 
 * 在「杨辉三角」中，每个数是它左上方和右上方的数的和。
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: rowIndex = 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: rowIndex = 0
 * 输出: [1]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: rowIndex = 1
 * 输出: [1,1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 0 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？
 * 
 */
#include <vector>
// @lc code=start
class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<std::vector<int>> res;
        for(int i = 0; i <= rowIndex; ++i) {
            std::vector<int> row;
            for(int j = 0; j <= i; ++j) {
                if(j == 0 || j == i) {
                    row.push_back(1);
                } else {
                    row.push_back(res[i - 1][j] + res[i - 1][j - 1]);
                }
            }
            res.push_back(row);
        }
        return res[rowIndex];
    }
};
// @lc code=end

