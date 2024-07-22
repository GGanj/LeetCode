/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (37.83%)
 * Likes:    1067
 * Dislikes: 0
 * Total Accepted:    336.9K
 * Total Submissions: 886.8K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，x^n^ ）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 2.00000, n = 10
 * 输出：1024.00000
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = 2.10000, n = 3
 * 输出：9.26100
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：x = 2.00000, n = -2
 * 输出：0.25000
 * 解释：2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * -10^4 <= x^n <= 10^4
 * 
 * 
 */
#include <iostream>
// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) {
            return 1;
        }

        double res = 1;

        if(n < 0) {
            x = 1/x;
        }

        while(n != 0) {
            if(n % 2 == 1 || n % 2 == -1) {
                res *= x;
            }
            x *= x;
            n /= 2;
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    double x = 2.10000;
    int n = 3;
    double res = solution.myPow(x, n);
    std::cout << res << std::endl;
    char * cc = "1577";
    std::cout << cc << std::endl;
    return 0;
}
