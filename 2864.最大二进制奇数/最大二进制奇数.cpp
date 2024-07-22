/*
 * @lc app=leetcode.cn id=2864 lang=cpp
 *
 * [2864] 最大二进制奇数
 *
 * https://leetcode.cn/problems/maximum-odd-binary-number/description/
 *
 * algorithms
 * Easy (80.79%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    30.1K
 * Total Submissions: 35.6K
 * Testcase Example:  '"010"'
 *
 * 给你一个 二进制 字符串 s ，其中至少包含一个 '1' 。
 * 
 * 你必须按某种方式 重新排列 字符串中的位，使得到的二进制数字是可以由该组合生成的 最大二进制奇数 。
 * 
 * 以字符串形式，表示并返回可以由给定组合生成的最大二进制奇数。
 * 
 * 注意 返回的结果字符串 可以 含前导零。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "010"
 * 输出："001"
 * 解释：因为字符串 s 中仅有一个 '1' ，其必须出现在最后一位上。所以答案是 "001" 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "0101"
 * 输出："1001"
 * 解释：其中一个 '1' 必须出现在最后一位上。而由剩下的数字可以生产的最大数字是 "100" 。所以答案是 "1001" 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 100
 * s 仅由 '0' 和 '1' 组成
 * s 中至少包含一个 '1'
 * 
 * 
 */
#include <string>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int oneCount = 0;
        int pLeft = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '1') {
                ++oneCount;
                s[i] = '0';
                s[pLeft++] = '1';
            }
        }
        s[pLeft - 1] = '0';
        s.back() = '1';
        return s;
    }
};
// @lc code=end

int main() {
    Solution s;
    string str;
    string ret = s.maximumOddBinaryNumber(str);
    std::cout << ret << std::endl;
    return 1; 
}

