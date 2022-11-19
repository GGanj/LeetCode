/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (60.59%)
 * Likes:    3913
 * Dislikes: 0
 * Total Accepted:    597.9K
 * Total Submissions: 961.4K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */
#include <vector>
#include <iostream>
// @lc code=start
class Solution {
public:
    int trap(std::vector<int>& height) {
        int res = 0, tmp = 0, left = 0, heightestIndex = 0;
        for(int i = heightestIndex; i < height.size(); ++i) {
            if(left == 0) { 
                if(height[i] != 0) {
                    left = height[i];
                    heightestIndex = i;
                }
                continue;
            }

            if(height[i] < left) {
                tmp += (left - height[i]); 
            } else {
                left = height[i];
                res += tmp;
                tmp = 0;
                heightestIndex = i;
            }
        }
        left = 0;
        tmp = 0;
        for(int i = height.size() - 1; i >= heightestIndex; --i) {
            if(left == 0) { 
                if(height[i] != 0) {
                    left = height[i];
                }
                continue;
            }

            if(height[i] < left) {
                tmp += (left - height[i]); 
            } else {
                left = height[i];
                res += tmp;
                tmp = 0;
            }
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution solution;
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = solution.trap(height);
    std::cout << res << std::endl;
    return 0;
}