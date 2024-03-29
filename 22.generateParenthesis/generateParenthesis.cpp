/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.43%)
 * Likes:    2613
 * Dislikes: 0
 * Total Accepted:    496.9K
 * Total Submissions: 641.7K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */
#include <string>
#include <vector>
// @lc code=start
class Solution {
public:
    std::vector<std::string> res;
    std::vector<std::string> generateParenthesis(int n) {
        nParenthesis(n - 1, n, "(");
        return res;
    }

    void nParenthesis(int left, int right, std::string str) {
        if(left == 0 && right == 0) {
            res.push_back(str);
        }
        if(left > 0) {
            str += "(";
            nParenthesis(left - 1, right, str);
            str.pop_back();
        }
        if(right > left) {
            str += ")";
            nParenthesis(left, right - 1, str);
            str.pop_back();
        }
    }


};
// @lc code=end

