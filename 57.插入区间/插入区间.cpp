/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 *
 * https://leetcode.cn/problems/insert-interval/description/
 *
 * algorithms
 * Medium (41.91%)
 * Likes:    692
 * Dislikes: 0
 * Total Accepted:    138.6K
 * Total Submissions: 330.8K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * 给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
 * 
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出：[[1,5],[6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出：[[1,2],[3,10],[12,16]]
 * 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 * 
 * 示例 3：
 * 
 * 
 * 输入：intervals = [], newInterval = [5,7]
 * 输出：[[5,7]]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：intervals = [[1,5]], newInterval = [2,3]
 * 输出：[[1,5]]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：intervals = [[1,5]], newInterval = [2,7]
 * 输出：[[1,7]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * intervals[i].length == 2
 * 0 
 * intervals 根据 intervals[i][0] 按 升序 排列
 * newInterval.length == 2
 * 0 
 * 
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) {
            return {newInterval};
        }
        vector<vector<int>> res;
        bool isMerged = false;
        for(int i = 0; i < intervals.size();) {
            int minValue = intervals[i][0], maxValue = intervals[i][1];
            if(isMerged) {
                int rightIndex = i + 1;
                while(rightIndex < intervals.size()) {
                    if(maxValue >= intervals[rightIndex][0]) {
                        maxValue = maxValue > intervals[rightIndex][1] ? maxValue : intervals[rightIndex][1];
                        ++rightIndex;
                    } else {
                        break;
                    }
                }
                res.push_back({minValue, maxValue});
                i = rightIndex;
            } else {
                if(intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0]) {
                    intervals[i][1] = maxValue > newInterval[1]? maxValue : newInterval[1];
                    isMerged = true;
                } else if(intervals[i][0] > newInterval[0] && intervals[i][0] <= newInterval[1]) {
                    intervals[i][0] = newInterval[0];
                    intervals[i][1] = maxValue > newInterval[1]? maxValue : newInterval[1];
                    isMerged = true;
                } else if(minValue > newInterval[0]) {
                    res.push_back(newInterval);
                    isMerged = true;
                } else {
                    res.push_back(intervals[i]);
                    ++i;
                }
            }
        }

        if(!isMerged) {
            res.push_back(newInterval);
        }

        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 8};
    Solution s;
    vector<vector<int>> res = s.insert(intervals, newInterval);
    for(auto i : res) {
        cout << i[0] << " " << i[1] << std::endl;
    }

    return 0;
}

