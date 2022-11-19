/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (74.64%)
 * Likes:    761
 * Dislikes: 0
 * Total Accepted:    305.3K
 * Total Submissions: 407.9K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
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
 * 输入: numRows = 5
 * 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: numRows = 1
 * 输出: [[1]]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * 
 * 
 */
#include <vector>
// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if(numRows == 0) {
            return {};
        }
        std::vector<std::vector<int>> res;
        for(int i = 0; i < numRows; ++i) {
            std::vector<int> layer;
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    layer.push_back(1);
                } else {
                    layer.push_back(res[i-1][j-1] + res[i-1][j]);
                }
            }
            res.push_back(layer);
        }
        return res;
    }
};
// @lc code=end

