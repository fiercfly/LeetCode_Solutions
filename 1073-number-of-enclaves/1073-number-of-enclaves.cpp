// ************** BFS ************

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        
        queue<pair<int, int>> q;   

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j] == 1){
                    vis[i][j]= 1;
                    q.push({i,j});
                }
            }
        } //All boundary land are vis and in queue

        int dir[]= {-1, 0 ,1, 0};
        int dic[] = {0, 1, 0 , -1};

        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;

            q.pop();


            for(int i=0; i<4; i++){
                int nr= row+ dir[i];
                int nc= col+ dic[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1){
                    q.push({nr, nc});
                    vis[nr][nc]= 1;
                }
            } 
        }

        int ans= 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};



// *************** DFS *************

// class Solution {
// public:
//     void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &vis){
//         if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j]==0 || vis[i][j]){
//             return;
//         }

//         vis[i][j]= 1;   
//         dfs(grid, i+1, j, vis);
//         dfs(grid, i-1, j, vis);
//         dfs(grid, i, j+1, vis);
//         dfs(grid, i, j-1, vis);
//     }

//     int numEnclaves(vector<vector<int>>& grid) {
//         int n= grid.size();
//         int m= grid[0].size();

//         vector<vector<int>> vis(n, vector<int>(m,0));

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1 ){
//                     dfs(grid, i, j, vis);
//                 }
//             }
//         }

//         //counting...

//         int ans=

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(!vis[i][j] && grid[i][j]==1){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

/*

Apply dfs on all cells attached on boundary
mark them as visited
Count the remaining non visited land cells and return them

*/