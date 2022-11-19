/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (54.17%)
 * Likes:    253
 * Dislikes: 0
 * Total Accepted:    131.3K
 * Total Submissions: 242K
 * Testcase Example:  '"hello"'
 *
 * 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
 * 
 * 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "hello"
 * 输出："holle"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "leetcode"
 * 输出："leotcede"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s 由 可打印的 ASCII 字符组成
 * 
 * 
 */
#include <string>
#include <unordered_set>
// @lc code=start
class Solution {
public:
    std::string reverseVowels(std::string s) {
        std::unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        std::string::iterator head = s.begin(), tail = s.end() - 1;
        while(head < tail) {
            if(vowelsSet.find(*head) == vowelsSet.end()) {
                ++head;
                continue;
            }
            if(vowelsSet.find(*tail) == vowelsSet.end()) {
                --tail;
                continue;
            }
            char tmp = *head;
            *head = *tail;
            *tail = tmp;
            ++head;
            --tail;
        }
        return s;
    }
};
// @lc code=end

