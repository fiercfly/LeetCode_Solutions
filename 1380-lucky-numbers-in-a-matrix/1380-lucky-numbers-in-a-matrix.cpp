class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i=0; i<matrix.size(); i++){
            int mini= INT_MAX;
            int ind= 0;
            for(int j=0;j<matrix[i].size(); j++){
                if(mini>matrix[i][j]){
                    ind= j;
                    mini= matrix[i][j];
                }
            }
            bool itIs= true;
            for(int x= 0; x<matrix.size(); x++){
                if(matrix[x][ind]>matrix[i][ind]){
                    itIs= false;
                    break;
                }
            }
            if(itIs){
                ans.push_back(matrix[i][ind]);
            }
        }
        return ans;
    }
};