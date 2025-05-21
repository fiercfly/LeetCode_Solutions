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

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
        
//         int n= matrix.size();
//         int m= matrix[0].size();
//         vector<int> row,col;
//         for(int i=0;i<n;++i){
//            for(int j=0;j<m;++j){
//                if(matrix[i][j] ==0){
//                     row.push_back(i); col.push_back(j);
//                }
//            }
              
//         }

//         for(int i=0; i<row.size(); ++i){
//             for(int j=0; j<m; ++j){
//                 matrix[row[i]][j] =0;
//             }
//         }

//         for(int j=0;j<col.size(); ++j){
//             for(int i=0;i<n;++i){
//                 matrix[i][col[j]] = 0;
//             }
//         }

        
//     }
// };