class Solution {
public:
    bool isValid(char num, vector<vector<char>> &board, int row, int col){
        for(int i=0; i<9; i++){
            if(board[i][col] == num){
                return false;
            }
        }
        for(int j= 0; j<9; j++){
            if(board[row][j] == num){
                return false;
            }
        }
        for(int i=0; i<9; i++){
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == num){
                return false;
            }
        }
        return true;
    }
    bool solveSudokus(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        
                        if (isValid(num, board, i, j)) {
                            board[i][j] = num;
                            if (solveSudokus(board)) {
                                return true;
                            }
                            else {
                                board[i][j]= '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    vector<vector<char>> solveSudoku(vector<vector<char>>& board) {
        solveSudokus(board);
        return board;
    }
};