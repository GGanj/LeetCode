/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (36.33%)
 * Likes:    1822
 * Dislikes: 0
 * Total Accepted:    266K
 * Total Submissions: 730.4K
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s[i] 为 '(' 或 ')'
 * 
 * 
 * 
 * 
 */
#include <iostream>
#include <stack>
#include <string>
// @lc code=start
class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> parenTheseStack;
        parenTheseStack.push(-1);
        int max = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') {
                parenTheseStack.emplace(i);
            } else {
                parenTheseStack.pop();
                if(parenTheseStack.empty()) {
                    parenTheseStack.push(i);
                } else {
                    int currLength = i - parenTheseStack.top();
                    max = max > currLength ? max : currLength;
                }
            }
        }
        return max;
    }
};
// @lc code=end

int main() {
    Solution solution;
    std::string s = ")()())";
    int res = solution.longestValidParentheses(s);
    std::cout << res << std::endl;
    return 0;
}

