/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (36.53%)
 * Likes:    5142
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.8M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */
#include <string>
#include <vector>
// @lc code=start
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); i++) {
            int x = i, y = i;
            
            while(x >= 0 && y < s.size()) {
                if(s[x] == s[y]) {
                    --x;
                    ++y;
                } else {
                    break;
                }
            }
            ++x;
            --y;
            if((right - left) < (y - x + 1)) {
                right = y;
                left = x;
            }
            x = i, y = i + 1;
            while(x >= 0 && y < s.size()) {
                if(s[x] == s[y]) {
                    --x;
                    ++y;
                } else {
                    break;
                }
            }
            ++x;
            --y;
            if((right - left) < (y - x + 1)) {
                right = y;
                left = x;
            }
        }
        return s.substr(left, right - left + 1);
    }
};
// @lc code=end

