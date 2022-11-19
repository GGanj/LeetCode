/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (64.57%)
 * Likes:    1230
 * Dislikes: 0
 * Total Accepted:    394.5K
 * Total Submissions: 604.4K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::unordered_set<int> selectedSet;
        arrange(nums, selectedSet, {});
        return res;
    }

    void arrange(std::vector<int>& nums, std::unordered_set<int>& selectedSet, std::vector<int> list) {
        if(list.size() == nums.size()) {
            res.emplace_back(list);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {
            if(selectedSet.find(i) == selectedSet.end()) {
                if(i > 0 && nums[i - 1] == nums[i] && selectedSet.find(i-1) != selectedSet.end()) {
                    continue;
                }
                list.push_back(nums[i]);
                selectedSet.insert(i);
                arrange(nums, selectedSet, list);
                selectedSet.erase(i);
                list.pop_back();
            }
        }
    }
};
// @lc code=end

int main() {
    Solution soltuion;
    std::vector<int> nums = {1, 1, 2};
    std::vector<std::vector<int>> res = soltuion.permuteUnique(nums);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < nums.size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
