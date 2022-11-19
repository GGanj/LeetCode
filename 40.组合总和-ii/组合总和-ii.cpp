/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.79%)
 * Likes:    1138
 * Dislikes: 0
 * Total Accepted:    361.4K
 * Total Submissions: 599K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 
 * 注意：解集不能包含重复的组合。 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 示例 2:
 * 
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */
#include <vector>
#include <algorithm>
// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        isCombina(candidates, {}, 0, target);
        return res;
    }

    void isCombina(std::vector<int>& candidates, std::vector<int> combina, int begin, int target) {
        if(target < 0) {
            return;
        }
        if(target == 0) {
            res.emplace_back(combina);
            return;
        }
        for(int i = begin; i < candidates.size(); ++i) {
            if(candidates[i] == -1) {
                continue;
            }
            int currNum = candidates[i];
            candidates[i] = -1;
            combina.push_back(currNum);
            isCombina(candidates, combina, i + 1, target - currNum);
            combina.pop_back();
            candidates[i] = currNum;
            while(i < (candidates.size() -1) && candidates[i + 1] == currNum) {
                ++i;
            }
        }
    }
};
// @lc code=end

void main() {
    Solution s;
    std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    std::vector<std::vector<int>> res = s.combinationSum2(candidates, target);
}
