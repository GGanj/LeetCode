/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (40.35%)
 * Likes:    1411
 * Dislikes: 0
 * Total Accepted:    635.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0
 * 开始）。如果不存在，则返回  -1 。
 * 
 * 
 * 
 * 说明：
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf()
 * 定义相符。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "hello", needle = "ll"
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "aaaaa", needle = "bba"
 * 输出：-1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：haystack = "", needle = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack 和 needle 仅由小写英文字符组成
 * 
 * 
 */
#include <string>
#include <vector>
#include <unordered_map>
// @lc code=start
class Solution {
public:
    std::vector<std::unordered_map<char, int>> dp;
    int strStr(std::string haystack, std::string needle) {
        kmp(needle);
        int hLength = haystack.size(), nLength = needle.size();
        int needleState = 0;
        for(int i = 0; i < hLength; ++i) {
            if(dp[needleState].find(haystack[i]) == dp[needleState].end()) {
                needleState = 0;
                continue;
            }
            needleState = dp[needleState][haystack[i]];
            if(needleState == nLength) {
                return i - nLength + 1;
            }
        }
        return -1;
    }

    void kmp(std::string pat) {
        int patLength = pat.size();
        int prefix = 0;
        std::unordered_map<char, int> stateBegin;
        stateBegin[pat[0]] = 1;
        dp.push_back(stateBegin);
        for(int i = 1; i < pat.length(); ++i) {
            std::unordered_map<char, int> newState = dp[prefix];
            newState[pat[i]] = i + 1;
            dp.push_back(newState);
            prefix= dp[prefix][pat[i]];
        }
    }
};
// @lc code=end

