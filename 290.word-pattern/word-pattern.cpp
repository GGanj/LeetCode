/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (45.30%)
 * Likes:    480
 * Dislikes: 0
 * Total Accepted:    106.8K
 * Total Submissions: 236.7K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 
 * 
 * 示例1:
 * 
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= pattern.length <= 300
 * pattern 只包含小写英文字母
 * 1 <= s.length <= 3000
 * s 只包含小写英文字母和 ' '
 * s 不包含 任何前导或尾随对空格
 * s 中每个单词都被 单个空格 分隔
 * 
 * 
 */
#include <string>
#include <unordered_map>
// @lc code=start
class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::string subStr;
        std::vector<std::string> subStrArr;
        std::unordered_map<char, std::string> trace1;
        std::unordered_map<std::string, char> trace2;
        for(char i : s) {
            if(i == ' ') {
                subStrArr.push_back(subStr);
                subStr = "";
            } else {
                subStr.push_back(i);
            }
        }
        subStrArr.push_back(subStr);
        subStr = "";
        if(pattern.size() != subStrArr.size()) {
            return false;
        }
        for(int i = 0; i < pattern.size(); ++i) {
            if(trace1.find(pattern[i]) != trace1.end() || trace2.find(subStrArr[i]) != trace2.end()) {
                if(trace1[pattern[i]] != subStrArr[i] || trace2[subStrArr[i]] != pattern[i]) {
                    return false;
                }
            } else {
                trace1[pattern[i]] = subStrArr[i];
                trace2[subStrArr[i]] = pattern[i];
            }
        }
        return true;
    }
};
// @lc code=end

