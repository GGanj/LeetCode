/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.28%)
 * Likes:    1325
 * Dislikes: 0
 * Total Accepted:    349.5K
 * Total Submissions: 709.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int colSize = matrix.size(), rowSize = matrix[0].size();
        int colPos = 0, rowPos = 0;
        type direction = right;
        vector<int> res = {};
        while(res.size() < colSize * rowSize) {
            res.push_back(matrix[colPos][rowPos]);
            matrix[colPos][rowPos] = INT_MIN;
            switch(direction) {
                case right: {
                    if((rowPos + 1) == rowSize || matrix[colPos][rowPos + 1] == INT_MIN) {
                        ++colPos;
                        direction = down;
                    } else {
                        ++rowPos;
                    }
                }
                break;
                case down: {
                    if(colPos + 1 == colSize || matrix[colPos + 1][rowPos] == INT_MIN) {
                        --rowPos;
                        direction = left;
                    } else {
                        ++colPos;
                    }
                }
                break;
                case left: {
                    if((rowPos - 1) < 0 || matrix[colPos][rowPos - 1] == INT_MIN) {
                        --colPos;
                        direction = up;
                    } else {
                        --rowPos;
                    }
                }
                break;
                case up: {
                    if(matrix[colPos - 1][rowPos] == INT_MIN) {
                        ++rowPos;
                        direction = right;
                    } else {
                        --colPos;
                    }
                }
                break;
            }
        }
        return res;
    }

    enum type {
        right,
        down,
        left,
        up
    };
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> res = s.spiralOrder(matrix);

    for(auto i : res) {
        std::cout << i << ' ';
    }
    
    return 0;
}
