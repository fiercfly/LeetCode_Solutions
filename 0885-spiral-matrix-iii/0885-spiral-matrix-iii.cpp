class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows,int cols,int rStart, int cStart) {
        ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);
        
        vector<vector<int>> ans;
        int num= 1;
        int r= rStart;
        int c= cStart;
        ans.push_back({r,c});

        //left right upo down
        int directions[4][2]= {{0,1},{1,0},{0,-1},{-1, 0}};
        int dir= 0;
        int steps= 1;

        while(num<rows*cols){
            for(int i= 0;i<2;i++){ //one ring covered 2 time
                for(int j= 0;j< steps;j++){
                    r+=directions[dir][0];
                    c+=directions[dir][1];
                    if (r>= 0 &&r< rows&& c>= 0&&c <cols){
                        ans.push_back({r,c});
                        num++;
                    }
                }
                dir =(dir+ 1)%4;
            }
            steps++;
        }

        return ans;
    }
};
