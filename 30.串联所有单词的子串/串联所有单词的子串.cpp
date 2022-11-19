/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (36.94%)
 * Likes:    651
 * Dislikes: 0
 * Total Accepted:    105.8K
 * Total Submissions: 285.8K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "barfoothefoobarman", words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * 输出：[6,9,12]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由小写英文字母组成
 * 1 
 * 1 
 * words[i] 由小写英文字母组成
 * 
 * 
 */
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
// @lc code=start
class Solution {
public:

    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        int wordLength = words[0].length(), strLength = s.length(), wordNum = words.size();
        if(s.length() < (wordLength * words.size())) {
            return {};
        }
        std::vector<int> res = {};
        for(int left = 0; left < wordLength && strLength - left >= wordLength * wordNum; ++left) {
            std::unordered_map<std::string, int> wordMap;
            for(int i = 0; i < wordNum; ++i) {
                ++wordMap[s.substr(left + i * wordLength, wordLength)];
            }
            for(std::string wordItem : words) {
                if(--wordMap[wordItem] == 0) {
                    wordMap.erase(wordItem);
                }
            }
            for(int subStrBegin = left; strLength - subStrBegin >= wordLength * wordNum; subStrBegin += wordLength) {
                if(wordMap.empty()) {
                    res.emplace_back(subStrBegin);
                }
                if(strLength - subStrBegin == wordLength * wordNum) {
                    continue;
                }
                if(--wordMap[s.substr(subStrBegin, wordLength)] == 0) {
                    wordMap.erase(s.substr(subStrBegin, wordLength));
                }
                if(++wordMap[s.substr(subStrBegin + wordLength * wordNum, wordLength)] == 0) {
                    wordMap.erase(s.substr(subStrBegin + wordLength * wordNum, wordLength));
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    std::vector<std::string> words = {"foo","bar"};
    std::string s = "barfoothefoobarman";
    std::vector<int> res = solution.findSubstring(s, words);
    for(int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

