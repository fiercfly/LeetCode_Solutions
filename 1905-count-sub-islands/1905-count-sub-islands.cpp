class Solution {
public:
    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &visited, int row, int col, bool &flag){
        if(row<0 || row>= grid1.size() ||  col<0 || col>=grid1[1].size() || grid2[row][col]==0 || visited[row][col]== true){
            return flag;
        }
        if(grid2[row][col]!=grid1[row][col]){
            flag= false;
        }
        visited[row][col]= true;
        
        dfs(grid1, grid2, visited, row-1, col, flag);
        dfs(grid1, grid2, visited, row+1, col, flag);
        dfs(grid1, grid2, visited, row, col+1, flag);
        dfs(grid1, grid2, visited, row, col-1, flag);
        return flag;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count= 0;
         vector<vector<bool>> visited(grid2.size(), vector<bool>(grid2[0].size(), 0));
        for(int i=0; i<grid2.size(); i++){
            for(int j= 0; j<grid2[i].size(); j++){
                if(grid2[i][j]!=0 && visited[i][j]!= true){
                    bool flag= true;
                    dfs(grid1, grid2, visited, i, j, flag);
                    if(flag){
                        count++;
                    }
                }  
            }
        }
        return count;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();