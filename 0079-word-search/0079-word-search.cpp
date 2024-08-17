class Solution {
public:
    bool generate(vector<vector<char>>& board,string word, int row, int col, string temp,vector<vector<int>> &vis){
        if(temp==word){
                return true;
        }
        
        if(row< 0|| row>= board.size()|| col<0|| col>=board[0].size()|| vis[row][col]== 1||board[row][col]!= word[temp.length()]){
            return false;
        }
        
        vis[row][col]=1;
        temp+= board[row][col];
        bool ans=  generate(board, word,row, col+1, temp, vis)||
                 generate(board, word,row, col-1, temp, vis)||
                generate(board, word,row+1, col, temp, vis)||
                generate(board, word,row-1, col, temp, vis);
        vis[row][col]= 0;
        return ans;        
    }
        
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(generate(board,word,i,j,"",vis)){
                    return true;
                }
            }
        }
        
        return false;

    }
};