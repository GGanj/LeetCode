/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (45.94%)
 * Likes:    1014
 * Dislikes: 0
 * Total Accepted:    486.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = [1,2,3]
 * 输出：[1,2,4]
 * 解释：输入数组表示数字 123。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = [4,3,2,1]
 * 输出：[4,3,2,2]
 * 解释：输入数组表示数字 4321。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = [0]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */
#include <vector>
// @lc code=start
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        if(digits.size() == 0) {
            return {};
        }
        std::vector<int>::iterator iter = digits.end() - 1;
        *iter += 1;
        while(iter > digits.begin() && *iter > 9) {
            *iter  = 0;
            *(iter - 1) += 1;
            --iter;
        }
        if(*digits.begin() > 9) {
            *digits.begin() = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end

