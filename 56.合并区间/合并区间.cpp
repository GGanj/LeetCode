/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (49.28%)
 * Likes:    1832
 * Dislikes: 0
 * Total Accepted:    600.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        // while(intervals.size()) {
        //     res.push_back(*intervals.begin());
        //     intervals.erase(intervals.begin());
        //     auto resLastIter = res.end() - 1;
        //     for(auto iIter = intervals.begin(); iIter != intervals.end();) {
        //         if((*resLastIter)[1] >= (*iIter)[0]) {
        //             (*resLastIter)[1] = (*resLastIter)[1] > (*iIter)[1] ? (*resLastIter)[1] : (*iIter)[1];
        //             iIter = intervals.erase(iIter);
        //         } else {
        //             break;
        //         }
        //     }
        // }
        for(int i = 0; i < intervals.size();) {
            int maxValue = intervals[i][1], rightIndex = i + 1;
            while(rightIndex < intervals.size()) {
                if(maxValue >= intervals[rightIndex][0]) {
                    maxValue = maxValue > intervals[rightIndex][1] ? maxValue : intervals[rightIndex][1];
                    ++rightIndex;
                } else {
                    break;
                }
            }
            res.push_back({intervals[i][0], maxValue});
            i = rightIndex;
        }
        return res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> intervals = {{4, 5}, {1, 2}};
    Solution s;
    vector<vector<int>> res = s.merge(intervals);
    for(auto i : res) {
        std::cout << i[0] << " " << i[1] << endl;
    }

    return 0;
}
