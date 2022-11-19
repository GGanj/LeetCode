/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.85%)
 * Likes:    1006
 * Dislikes: 0
 * Total Accepted:    533K
 * Total Submissions: 1.4M
 * Testcase Example:  '4'
 *
 * 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
 * 
 * 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
 * 
 * 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 4
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = 8
 * 输出：2
 * 解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= x <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, mid = left + (right - left) / 2;
        while(left <= right) {
            mid = left + (right - left) / 2;
            long long tmp = (long long)mid * (long long)mid;
            if(tmp == x) {
                return mid;
            }
            if(left == right) {
                return tmp > x ? mid - 1 : mid;
            }
            if(tmp < x) {
                left = mid + 1;
                continue;
            }
            if(tmp > x) {
                right = mid;
                continue;
            }
        }
        return mid;
    }

};
// @lc code=end

