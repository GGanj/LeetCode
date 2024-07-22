/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (73.73%)
 * Likes:    1260
 * Dislikes: 0
 * Total Accepted:    397.4K
 * Total Submissions: 557.1K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        for(int i = 0; i < n; ++i) {
            vector<int> row;
            for(int j = 0; j < n; ++j) {
                row.push_back(0);
            }
            ret.push_back(row);
        }

        Direct d = right;
        int x = 0, y = 0;
        int i = 1;
        while(i <= n * n) {
            switch(d) {
                case right: 
                if(y < n && ret[x][y] == 0) {
                    ret[x][y] = i++;
                    ++y;
                } else {
                    d = down;
                    --y;
                    ++x;
                }
                break;
                case down:
                if(x < n && ret[x][y] == 0) {
                    ret[x][y] = i++;
                    ++x;
                } else {
                    d = left;
                    --x;
                    --y;
                }
                break;
                case left:
                if(y >=0 && ret[x][y] == 0) {
                    ret[x][y] = i++;
                    --y;
                } else {
                    d = up;
                    ++y;
                    --x;
                }
                break;
                case up:                
                if(x >= 0 && ret[x][y] == 0) {
                    ret[x][y] = i++;
                    --x;
                } else {
                    d = right;
                    ++x;
                    ++y;
                }
                break;
            }
        }
        return ret;
    }
    
    enum Direct{
        right,
        down,
        left,
        up
    };
};
// @lc code=end

int main() {
    int n;
    std::cin >> n;
    Solution s;
    vector<vector<int>> ret = s.generateMatrix(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout.width(5);
            std::cout << ret[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}

