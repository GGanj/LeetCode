/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 *
 * https://leetcode.cn/problems/permutation-sequence/description/
 *
 * algorithms
 * Hard (53.63%)
 * Likes:    832
 * Dislikes: 0
 * Total Accepted:    138.6K
 * Total Submissions: 258.4K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3, k = 3
 * 输出："213"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 4, k = 9
 * 输出："2314"
 * 
 * 
 * 1234
 * 1243
 * 1324
 * 1342
 * 1423
 * 1432 3!  6
 * 
 * 
 * 
 * 2134
 * 2143
 * 2314
 * 2343
 * 2413
 * 2431
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 3, k = 1
 * 输出："123"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */
#include <iostream>
#include <string>
#include <deque>
using namespace std;
// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        deque<int> numArr = {1}, countArr = {1};
        for(int i = 2; i < n; ++i) {
            numArr.push_back(i);
            countArr.push_front(*countArr.begin() * i);
        }
        numArr.push_back(n);
        string ret;
        int pos = 0;
        while(k > 0 && pos < n) {
            if(k >= countArr[pos]) {
                int x = k / countArr[pos];
                int y = k % countArr[pos];
                if (y > 0) {
                    ret.append(std::to_string(x + 1));
                    k -= x * countArr[pos];
                } else{
                    ret.append(std::to_string(x));
                    k -= (x - 1) * countArr[pos];
                }
            } else  {
                ret.append("1");
            }
            ++pos;
        }

        for(int i = 0; i < n; ++i) {
            int index = ret[i] - '0';
            for(int j = 0; j < index; ++j) {
                if(numArr[j] == 0) {
                    ++index;
                }
            }
            ret[i] = '0' + numArr[index - 1];
            numArr[index - 1] = 0;

        }
        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    int n, k;
    std::cout << "Input n & k" << std::endl;
    std::cin >> n >> k;
    string ret = s.getPermutation(n, k);
    std::cout << ret << std::endl;
    return 0;
}

