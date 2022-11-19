/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (42.25%)
 * Likes:    2217
 * Dislikes: 0
 * Total Accepted:    818.7K
 * Total Submissions: 1.9M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */
#include <string>
#include <vector>
// @lc code=start
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string res = "", tmp = "";
        std::string::iterator iter1;
        std::vector<std::string>::iterator iter2;
        int pos = 0;
        for(iter1 = strs[0].begin();iter1 != strs[0].end(); ++iter1) {
            tmp = tmp + *iter1;
            for(iter2 = strs.begin();iter2 != strs.end(); ++iter2) {
                pos = (*iter2).find(tmp);
                if(pos == std::string::npos || pos != 0) {
                    return res;
                }
            }
            res = tmp;
        }
        return res;
    }
};
// @lc code=end

