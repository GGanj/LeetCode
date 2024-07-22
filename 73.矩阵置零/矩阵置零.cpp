/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode.cn/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (65.65%)
 * Likes:    1032
 * Dislikes: 0
 * Total Accepted:    332K
 * Total Submissions: 505.3K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个仅使用常量空间的解决方案吗？
 * 
 * 
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowZero = false, colZero = false;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == 0) {
                    if(i == 0 && !rowZero) {
                        rowZero = true;
                    }
                    if(j == 0 && !colZero) {
                        colZero = true;
                    }
                    
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                }
            }
        }

        for(int i = 1; i < matrix.size(); ++i) {
            for(int j = 1; j < matrix[0].size(); ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(rowZero) {
            for(int i = 0; i < matrix[0].size(); ++i) {
                matrix[0][i] = 0;
            }
        }

        if(colZero) {
            for(int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }

    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> matrix = {{0,1}};
    s.setZeroes(matrix);
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[0].size(); ++j) {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

