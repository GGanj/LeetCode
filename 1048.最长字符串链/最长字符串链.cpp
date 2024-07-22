/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 *
 * https://leetcode.cn/problems/longest-string-chain/description/
 *
 * algorithms
 * Medium (48.91%)
 * Likes:    267
 * Dislikes: 0
 * Total Accepted:    28.4K
 * Total Submissions: 52.6K
 * Testcase Example:  '["a","b","ba","bca","bda","bdca"]'
 *
 * 给出一个单词数组 words ，其中每个单词都由小写英文字母组成。
 * 
 * 如果我们可以 不改变其他字符的顺序 ，在 wordA 的任何地方添加 恰好一个 字母使其变成 wordB ，那么我们认为 wordA 是 wordB 的
 * 前身 。
 * 
 * 
 * 例如，"abc" 是 "abac" 的 前身 ，而 "cba" 不是 "bcad" 的 前身
 * 
 * 
 * 词链是单词 [word_1, word_2, ..., word_k] 组成的序列，k >= 1，其中 word1 是 word2 的前身，word2
 * 是 word3 的前身，依此类推。一个单词通常是 k == 1 的 单词链 。
 * 
 * 从给定单词列表 words 中选择单词组成词链，返回 词链的 最长可能长度 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["a","b","ba","bca","bda","bdca"]
 * 输出：4
 * 解释：最长单词链之一为 ["a","ba","bda","bdca"]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 * 输出：5
 * 解释：所有的单词都可以放入单词链 ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入：words = ["abcd","dbqca"]
 * 输出：1
 * 解释：字链["abcd"]是最长的字链之一。
 * ["abcd"，"dbqca"]不是一个有效的单词链，因为字母的顺序被改变了。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 16
 * words[i] 仅由小写英文字母组成。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    bool cmpStr(string a, string b) {
        int extra = 1;
        auto aIter = a.begin() , bIter = b.begin();
        while(extra >= 0 && aIter != a.end() && bIter != b.end()) {
            if(*aIter == *bIter) {
                ++aIter;
                ++bIter;
            } else {
                ++bIter;
                --extra;
            }
        }

        while(bIter != b.end()) {
            ++bIter;
            --extra;
        }

        return extra == 0;
    }

    int longestStrChain(vector<string>& words) {
        if(words.size() == 0 || words.size() == 1) {
            return words.size();
        }

        map<int, vector<string>> sortedWordsMap;
        unordered_map<string, int> linkLenMap;
        int ret = 1;

        for(int i = 0; i < words.size(); ++i) {
            sortedWordsMap[words[i].size()].push_back(words[i]);
            linkLenMap[words[i]] = 1;
        }

        auto swIter1 = sortedWordsMap.begin();
        auto swIter2 = ++sortedWordsMap.begin();
        while(swIter2 != sortedWordsMap.end()) {
            if((*swIter2).first - (*swIter1).first == 1) {
                for(auto str2 : (*swIter2).second) {
                    for(auto str1 : (*swIter1).second) {
                        if(cmpStr(str1, str2)) {
                            linkLenMap[str2] =  linkLenMap[str1] + 1 > linkLenMap[str2] ? linkLenMap[str1] + 1 : linkLenMap[str2];
                        }
                        ret =  linkLenMap[str2] > ret ? linkLenMap[str2] : ret;
                    }
                }
            } else {
                for(auto str : (*swIter1).second) {
                    linkLenMap[str] = linkLenMap[str] > 1 ? linkLenMap[str] : 1;
                }
                for(auto str : (*swIter2).second) {
                    linkLenMap[str] = 1;
                }
            }
            swIter1 = swIter2;
            ++swIter2;
        }
        return ret;
    }
};
// @lc code=end

int main() {
    vector<string> words = {"a","ab","ac","bd","abc","abd","abdd"};
    Solution s;
    int ret = s.longestStrChain(words);
    std::cout << ret << std::endl;
    return 0;
}

