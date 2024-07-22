/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 *
 * https://leetcode.cn/problems/bulls-and-cows/description/
 *
 * algorithms
 * Medium (59.07%)
 * Likes:    337
 * Dislikes: 0
 * Total Accepted:    100.7K
 * Total Submissions: 170.4K
 * Testcase Example:  '"1807"\n"7810"'
 *
 * 你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：
 * 
 * 写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：
 * 
 * 
 * 猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls"，公牛），
 * 有多少位属于数字猜对了但是位置不对（称为 "Cows"，奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
 * 
 * 
 * 给你一个秘密数字 secret 和朋友猜测的数字 guess ，请你返回对朋友这次猜测的提示。
 * 
 * 提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。
 * 
 * 请注意秘密数字和朋友猜测的数字都可能含有重复数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：secret = "1807", guess = "7810"
 * 输出："1A3B"
 * 解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
 * "1807"
 * ⁠  |
 * "7810"
 * 
 * 示例 2：
 * 
 * 
 * 输入：secret = "1123", guess = "0111"
 * 输出："1A1B"
 * 解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
 * "1123"        "1123"
 * ⁠  |      or     |
 * "0111"        "0111"
 * 注意，两个不匹配的 1 中，只有一个会算作奶牛（数字猜对位置不对）。通过重新排列非公牛数字，其中仅有一个 1 可以成为公牛数字。
 * 
 * 18707
 * 78170
 * 提示：
 * 
 * 
 * 1 <= secret.length, guess.length <= 1000
 * secret.length == guess.length
 * secret 和 guess 仅由数字组成
 * 
 * 
 */
#include <iostream>
#include <string>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.size();
        int bull = 0, cow = 0;
        set<char> cowSet;
        for(int i = 0; i < len; ++i) {
            if(secret[i] == guess[i]) {
                secret[i] = 'x';
                guess[i] = 'x';
                ++bull;
            }
        }
        for(int i = 0; i < len; ++i) {
            if(guess[i] == 'x') {
                continue;
            }
            // if(cowSet.find(guess[i]) == cowSet.end()) {
            //     if(secret.find(guess[i]) != std::string::npos) {
            //         ++cow;
            //     }
            //     cowSet.insert(guess[i]);
            // }
            int index = secret.find(guess[i]);
            if(index != std::string::npos) {
                secret[index] = 'x';
                ++cow;
            }
        }
        string ret;
        ret.append(to_string(bull));
        ret.append("A");
        ret.append(to_string(cow));
        ret.append("B");
        return ret;
    }
};
// @lc code=end

int main() {
    Solution sol;
    string s = "1123";
    string g = "0111";
    string ret = sol.getHint(s, g);
    std::cout << ret << std::endl;
    return 1;
}

