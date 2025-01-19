class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> & board,int dir[], int dic[]){
        vis[row][col]= 1;
        int n= board.size();
        int m= board[0].size();

        for(int i=0; i<4; i++){
            int nr= row+ dir[i];
            int nc= col+ dic[i];

            if(nr >= 0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr, nc, vis, board, dir, dic);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();

        int dir[]= {-1,0, 1, 0};
        int dic[]= {0,1,0,-1};

        vector<vector<int>> vis(n, vector<int>(m,0));

        
        for(int j=0; j<m; j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j, vis,board, dir, dic);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1, j, vis,board, dir, dic);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, vis,board, dir, dic);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i, m-1, vis,board, dir, dic);
            }
        }

        //removal...

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    board[i][j]= 'X';
                }
            }
        }
    }
};