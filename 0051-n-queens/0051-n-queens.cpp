class Solution {
public:
    void generate(vector<vector<string>> &ans,vector<vector<char>> &board,int n, int row){
        if(row>= n) {
            vector<string>temp;
            for(int i= 0;i< n;i++){
                temp.push_back(string(board[i].begin(), board[i].end()));
            }
            ans.push_back(temp);
            return;
        }

       for(int j=0; j<n; j++){
            if(isPossible(board, n, row,j)){
                board[row][j]= 'Q';
                generate(ans, board,n, row+1);
                board[row][j]= '.';
            }
       }

    }
    bool isPossible(vector<vector<char>> board,int n, int row, int col){
        //go in 3 dirctns: up, left diagnol, right diagnol
        //up
        for(int i=row; i>=0; i--){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //left dignol
        for(int i=row,j=col; i>=0 && j>=0;i--,j--){
            if(board[i][j]== 'Q'){
                return false;
            }
        }

        //right diagnol
        for(int i=row, j= col; i>=0 &&j<n; i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n,vector<char>(n, '.'));
        generate(ans,board, n, 0);
        return ans;
    }
};
    auto init = []()
        { 
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            return 'c';
        }();