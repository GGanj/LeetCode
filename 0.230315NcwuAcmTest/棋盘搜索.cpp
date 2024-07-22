#include <iostream>

using namespace std;

#define rowSize 10
#define colSize 9


bool search(char (board) [rowSize][colSize], pair<int, int> bPosition, const pair<int, int> rPosition) {
    if(bPosition.first == rPosition.first && bPosition.second == rPosition.second) {
        return true;
    }
    if(bPosition.first < 0 || bPosition.first >= rowSize || bPosition.second < 0 || bPosition.second >= colSize) {
        return false;
    }
    if(board[bPosition.first][bPosition.second] == '1') {
        return false;
    }
    board[bPosition.first][bPosition.second] = '1';
    return search(board, {bPosition.first + 1, bPosition.second}, rPosition) || search(board, {bPosition.first - 1, bPosition.second}, rPosition) 
        || search(board, {bPosition.first, bPosition.second + 1}, rPosition) || search(board, {bPosition.first, bPosition.second - 1}, rPosition); 
}

int main() {
    char board[rowSize][colSize];
    pair<int, int> bPosition, rPosition;
    for(int i = 0; i < rowSize; ++i) {
        for(int j = 0; j < colSize; ++j) {
            char chess;
            while((chess = cin.get()) == '\n');
            board[i][j] = chess;
            if(chess == '2') {
                bPosition = {i, j};
            } else if(chess == '3') {
                rPosition = {i, j};
            }
        }
    }
    cout << (search(board, bPosition, rPosition) ? "yes" : "no") << endl;
    return 0;
}