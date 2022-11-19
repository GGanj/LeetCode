/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (54.73%)
 * Likes:    562
 * Dislikes: 0
 * Total Accepted:    310.5K
 * Total Submissions: 563.4K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: s = "leetcode"
 * 输出: 0
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "loveleetcode"
 * 输出: 2
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "aabb"
 * 输出: -1
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只包含小写字母
 * 
 * 
 */
#include <string>
#include <unordered_map>
#include <queue>
// @lc code=start
class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> traceMap;
        std::queue<std::pair<char, int>> traceQueue;
        for(int i = 0; i < s.size(); ++i) {
            if(traceMap.find(s[i]) == traceMap.end()) {
                traceMap[s[i]] = i;
                traceQueue.emplace(s[i], i);
            } else {
                traceMap[s[i]] = -1;
                while(!traceQueue.empty() && traceMap[traceQueue.front().first] == -1) {
                    traceQueue.pop();
                };
            }
            
        }
        
        return traceQueue.size() == 0 ? -1 : traceQueue.front().second;
    }
};
// @lc code=end

