/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (53.89%)
 * Likes:    812
 * Dislikes: 0
 * Total Accepted:    246.5K
 * Total Submissions: 457.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */
#include <string>
// @lc code=start
class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string::iterator iter1 = a.end() - 1, iter2 = b.end() - 1;
        std::string res = "";
        int into = 0;
        while(iter1 >= a.begin() && iter2 >= b.begin()) {
            into = *iter1 / '1' + *iter2 / '1' + into;
            res.insert(res.begin(), ('0' + into % 2));
            into /= 2;
            --iter1;
            --iter2;
        }
        while(iter1 >= a.begin()) {
            into = *iter1 / '1' + into;
            res.insert(res.begin(), ('0' + into % 2));
            into /= 2;
            --iter1;
        }
        while(iter2 >= b.begin()) {
            into = *iter2 / '1' + into;
            res.insert(res.begin(), ('0' + into % 2));
            into /= 2;
            --iter2;
        }
        if(into == 1) {
            res.insert(res.begin(), '1');
        }
        return res;
    }
};
// @lc code=end

