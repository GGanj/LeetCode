/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (57.75%)
 * Likes:    1873
 * Dislikes: 0
 * Total Accepted:    475.8K
 * Total Submissions: 823.8K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */
#include <vector>
#include <string>
#include <iostream>
// @lc code=start
class Solution {
public:
    std::vector<std::string> keys = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> res;
    std::vector<std::string> letterCombinations(std::string digits) {
        if(digits.size() == 0) {
            return {};
        }
        backTrack(digits, 0, "");
        return res;
    }

    void backTrack(std::string digits, int index, std::string subStr) {
        if(subStr.size() == digits.size()) {
            res.push_back(subStr);
            return;
        }
        for(;index < digits.size(); ++index) {
            int digit = digits[index] - '0' - 2;
            std::string::iterator iter;
            for(iter = keys[digit].begin(); iter < keys[digit].end(); ++iter) {
                subStr += *iter;
                backTrack(digits, index + 1, subStr);
                subStr.pop_back();
            }
        }
    }
};
// @lc code=end

