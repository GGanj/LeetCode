/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (46.93%)
 * Likes:    540
 * Dislikes: 0
 * Total Accepted:    374.1K
 * Total Submissions: 797.3K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 解释："amanaplanacanalpanama" 是回文串
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "race a car"
 * 输出: false
 * 解释："raceacar" 不是回文串
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 字符串 s 由 ASCII 字符组成
 * 
 * 
 */
#include <string>
// @lc code=start
class Solution {
public:
    bool isPalindrome(std::string s) {
        if(s.length() == 0) {
            return true;
        }
        std::string::iterator iterHead = s.begin();
        std::string::iterator iterTail = s.end() - 1;
        while(iterHead < iterTail) {
            while(*iterHead < 48 || (*iterHead > 57 && *iterHead < 65) || (*iterHead > 90 && *iterHead < 97) || *iterHead > 122) {
                if(iterHead == iterTail) {
                    return true;
                }
                ++iterHead;
            }
            while(*iterTail < 48 || (*iterTail > 57 && *iterTail < 65) || (*iterTail > 90 && *iterTail < 97) || *iterTail > 122) {
                if(iterHead == iterTail) {
                    return true;
                }
                --iterTail;
            }
            if(*iterHead == *iterTail) {
                ++iterHead;
                --iterTail;
            } else {
                if((*iterHead > 47 && *iterHead < 58) || (*iterTail > 47 && *iterTail < 58)) {
                    return false;
                }
                if((*iterHead - *iterTail) == 32 || (*iterHead - *iterTail) == -32) {
                    ++iterHead;
                    --iterTail;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

