/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.20%)
 * Likes:    1308
 * Dislikes: 0
 * Total Accepted:    399.2K
 * Total Submissions: 589.5K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 * 
 * 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * 
 * 示例 2:
 * 
 * 
 * 输入: strs = [""]
 * 输出: [[""]]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 * 
 * 
 */
#include <vector>
#include <string>
#include <iostream>
// @lc code=start
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        while(!strs.empty()) {
            std::vector<std::string> group;
            std::vector<std::string>::iterator strsIter = strs.begin();
            std::string baseStr = *strsIter;
            strsIter = strs.erase(strsIter);
            group.push_back(baseStr);
            while(strsIter != strs.end()) {
                if(baseStr.size() == (*strsIter).size()) {
                    int index = 0;
                    std::string currStr = *strsIter;
                    for(int i = 0; i < baseStr.size(); ++i) {
                        index = currStr.find(baseStr[i]);
                        if(index < 0) {
                            break;
                        }
                        currStr[index] = '0';
                    }
                    if(index >= 0) {
                        group.push_back(*strsIter);
                        strsIter = strs.erase(strsIter);
                        continue;
                    }
                }
                ++strsIter;
            }
            res.emplace_back(group);
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::string> strs = {"ddddddddddg", "dgggggggggg"};
    std::vector<std::vector<std::string>> res = solution.groupAnagrams(strs);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}