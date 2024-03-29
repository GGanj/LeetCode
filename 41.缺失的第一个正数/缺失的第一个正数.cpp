/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (42.50%)
 * Likes:    1658
 * Dislikes: 0
 * Total Accepted:    262.9K
 * Total Submissions: 614.8K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,0]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <unordered_map>
// @lc code=start
class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int len = nums.size();
        std::unordered_map<int, int> numsMap;
        for(int i = 0; i < len; ++i) {
            ++numsMap[i + 1];
            --numsMap[nums[i]];
        }
        for(int i = 1; i <= len; ++i) {
            if(numsMap[i] == 1) {
                return i;
            }
        }
        return len + 1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    std::vector<int> nums = {2, 1, 5};
    int res = solution.firstMissingPositive(nums);
    std::cout << res << std::endl;
    return 0;
}

