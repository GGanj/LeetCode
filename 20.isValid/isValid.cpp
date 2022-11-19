/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.55%)
 * Likes:    3224
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.4M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "([)]"
 * 输出：false
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：s = "{[]}"
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */
#include <vector>
#include <string>
// @lc code=start
class Solution {
public:
    bool isValid(std::string s) {
        if(s.size() % 2 == 1) {
            return false;
        }
        std::string::iterator iter;
        std::vector<char> stack;
        for(iter = s.begin(); iter < s.end(); ++iter) {
            if(*iter == '(' || *iter == '[' || *iter == '{') {
                stack.push_back(*iter);
                continue;
            }
            if(stack.size() > 0
                && (*iter == ')' && *(stack.end() - 1) == '(')
                || (*iter == ']' && *(stack.end() - 1) == '[')
                || (*iter == '}' && *(stack.end() -1) == '{')
            ) {
                stack.pop_back();
                continue;
            }
            return false;
        }
        if(stack.size() == 0) {
            return true;
        }
        return false;
    }
};
// @lc code=end

