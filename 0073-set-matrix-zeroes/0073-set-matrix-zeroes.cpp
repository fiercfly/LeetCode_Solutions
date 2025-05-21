class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector <int> cl,rw;
        int m= matrix.size();
        int n= matrix[0].size();
        for(int i=0;i<m; i++){
            for(int j=0;j<n; j++){
                if(matrix[i][j] == 0){
                    rw.push_back(i);
                    cl.push_back(j);
                }
            }
        }

        for(int i=0;i<rw.size(); i++){
            for(int j=0; j<n; j++){
                matrix[rw[i]][j] = 0;
            }
        }

        
        for(int j= 0; j<cl.size(); j++){
            for(int i=0; i<m; i++){
                matrix[i][cl[j]] = 0;
            }
        }
    }
};