/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.85%)
 * Likes:    1083
 * Dislikes: 0
 * Total Accepted:    267.6K
 * Total Submissions: 599.1K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num1.length, num2.length <= 200
 * num1 和 num2 只能由数字组成。
 * num1 和 num2 都不包含任何前导零，除了数字0本身。
 * 
 * 
 */
#include <string>
#include <iostream>
// @lc code=start
class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if(num1 == "0" || num2 == "0") {
            return "0";
        }
        int tmp = 0, unit = 1;
        std::string res = "";
        for(int i = num1.size() - 1; i >= 0; --i) {
            std::string curr = "";
            for(int j = 1; j < unit; ++j) {
                curr.push_back('0');
            }
            for(int j = num2.size() - 1; j >= 0; --j) {
                tmp = (num1[i] - '0') * (num2[j] - '0') + tmp;
                curr.push_back(tmp % 10 + '0');
                tmp /= 10;
            }
            while(tmp != 0) {
                curr.push_back(tmp % 10 + '0');
                tmp /= 10;
            }
            res = addString(res, curr);
            ++unit;
        }
        return res;
    }

    std::string addString(std::string res, std::string curr) {
        std::reverse(res.begin(), res.end());
        std::string::iterator resIter = res.begin(), currIter = curr.begin();
        int tmp = 0;
        std::string newStr = "";
        while(resIter != res.end() || currIter != curr.end() || tmp != 0) {
            int resItem = resIter != res.end() ? (*resIter - '0') : 0;
            int currItem = currIter != curr.end() ? (*currIter - '0') : 0;
            tmp = resItem + currItem + tmp;
            newStr.push_back(tmp % 10 + '0');
            tmp /= 10;
            if(resIter != res.end()) {
                ++resIter;
            }
            if(currIter != curr.end()) {
                ++currIter;
            }
        }
        std::reverse(newStr.begin(), newStr.end());
        return newStr;
    }
};

// @lc code=end

int main() {
    Solution solution;
    std::string num1 = "123", num2 = "456";
    std::string res = solution.multiply(num1, num2);
    std::cout << res << std::endl;
    return 0;
}