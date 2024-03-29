/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 *
 * https://leetcode-cn.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (33.19%)
 * Likes:    961
 * Dislikes: 0
 * Total Accepted:    124.3K
 * Total Submissions: 369.4K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 * 
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 * 
 * 
 * 两个字符串完全匹配才算匹配成功。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输出: false
 * 
 */
#include <string>
#include <iostream>
#include <vector>
// @lc code=start
class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        const int sSize = s.size(), pSize = p.size();
        std::vector<std::vector<bool>> dp(sSize + 1, std::vector<bool>(pSize + 1));
        dp[0][0] = true;
        for(int indexP = 0; indexP <pSize; ++indexP) {
            if(p[indexP] == '*') {
                dp[0][indexP + 1] = dp[0][indexP];
            } else {
                dp[0][indexP + 1] = false;
            }
        }

        for(int indexS = 0; indexS < sSize; ++indexS) {
            for(int indexP = 0; indexP < pSize; ++indexP) {
                if(p[indexP] == '*') {
                    dp[indexS + 1][indexP + 1] = dp[indexS][indexP + 1] || dp[indexS + 1][indexP];
                } else {
                    dp[indexS + 1][indexP + 1] = dp[indexS][indexP] && (s[indexS] == p[indexP] || p[indexP] == '?');
                }
            }
        }

        return dp[sSize][pSize];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // std::string s = "abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab", p = "*aabb***aa**a******aa*";
    std::string s = "adceb", p = "*a*b";
    bool res = solution.isMatch(s, p);
    std::cout << res << std::endl;
    return 0;
}
