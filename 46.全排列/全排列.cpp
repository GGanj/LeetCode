/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (78.52%)
 * Likes:    2283
 * Dislikes: 0
 * Total Accepted:    753.2K
 * Total Submissions: 956.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 * 
 * 
 */
#include <vector>
#include <iostream>
// @lc code=start
class Solution {
public:
std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        arrange(nums, {});
        return res;
    }

    void arrange(std::vector<int>& nums, std::vector<int> list) {
        if(nums.size() == 0) {
            res.emplace_back(list);
            return;
        }
        std::vector<int>::iterator numsIter = nums.begin();
        while(numsIter != nums.end()) {
            int currNum = *numsIter;
            list.push_back(currNum);
            numsIter = nums.erase(numsIter);
            arrange(nums, list);
            numsIter = nums.insert(numsIter, currNum);
            list.pop_back();
            ++numsIter;
        }
    }
};
// @lc code=end

int main() {
    Solution soltuion;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> res = soltuion.permute(nums);
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < nums.size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
