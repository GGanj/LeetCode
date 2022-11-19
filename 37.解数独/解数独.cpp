/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (67.37%)
 * Likes:    1443
 * Dislikes: 0
 * Total Accepted:    175.9K
 * Total Submissions: 260.2K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过填充空格来解决数独问题。
 * 
 * 数独的解法需 遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 * 
 * 
 * 数独部分空格内已填入了数字，空白格用 '.' 表示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * 
 * 输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * 解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] 是一位数字或者 '.'
 * 题目数据 保证 输入数独仅有一个解
 * 
 * 
 * 
 * 
 * 
 */
#include <vector>
#include <iostream>
// @lc code=start
class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        fillSudoku(board);
    }

    bool fillSudoku(std::vector<std::vector<char>>& board, int colIndex = 0, int rowIndex = 0) {
        for(colIndex; colIndex < 9; ++colIndex) {
            for(rowIndex; rowIndex < 9; ++rowIndex) {
                if(board[colIndex][rowIndex] != '.') {
                    continue;
                } else {
                    for(int i = 1; i < 10; ++i) {
                        if(!checkRepeat(colIndex, rowIndex, board, ('0' + i))) {
                            board[colIndex][rowIndex] = ('0' + i);
                            if(fillSudoku(board, colIndex + (rowIndex + 1) / 9, (rowIndex + 1) % 9)) {
                                return true;
                            }
                            // if(fillSudoku(board)) {
                            //     return true;
                            // }
                            board[colIndex][rowIndex] = '.';
                        }
                    }
                    if(board[colIndex][rowIndex] == '.') {
                        return false;
                    }
                }
            }
            rowIndex = 0;
        }
        return true;
    }

        // {'5','3','.','.','7','.','.','.','.'},
        // {'6','.','.','1','9','5','.','.','.'},
        // {'.','9','8','.','.','.','.','6','.'},
        // {'8','.','.','.','6','.','.','.','3'},
        // {'4','.','.','8','.','3','.','.','1'},
        // {'7','.','.','.','2','.','.','.','6'},
        // {'.','6','.','.','.','.','2','8','.'},
        // {'.','.','.','4','1','9','.','.','5'},
        // {'.','.','.','.','8','.','.','7','9'}

    bool checkRepeat(int colIndex, int rowIndex, std::vector<std::vector<char>>& board, char val) {
        for(int i = 0; i < 9; ++i) {
            if(board[colIndex][i] == val) {
                return true;
            }
        }
        for(int i = 0; i < 9; ++i) {
            if(board[i][rowIndex] == val) {
                return true;
            }
        }
        colIndex = colIndex / 3 * 3;
        rowIndex = rowIndex / 3 * 3;
        for(int i = 0; i < 9; ++i) {
            if(board[colIndex + i / 3][rowIndex + i % 3] == val) {
                return true;
            } 
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solution.solveSudoku(board);
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

