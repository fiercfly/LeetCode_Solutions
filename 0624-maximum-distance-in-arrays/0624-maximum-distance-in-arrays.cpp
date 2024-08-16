class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        
        int mini=INT_MAX;
        int maxi= INT_MIN;
        int secondMini=INT_MAX;
        int secondMax= INT_MIN;
        int m=arrays.size();
        int minIn,maxIn= -1;
        for(int i=0; i<m; i++){

            if(mini>arrays[i][0]){
                secondMini= mini;
                mini= arrays[i][0];
                minIn= i;
            }
            else if(secondMini>arrays[i][0]){
                secondMini= arrays[i][0];
            }

            if(maxi<arrays[i][arrays[i].size()-1]){
                secondMax= maxi;
                maxi=arrays[i][arrays[i].size()-1];
                maxIn= i;
            }
            else if(secondMax<arrays[i].back()){
                secondMax= arrays[i].back();
            }
            
        }

        if(minIn!=maxIn){
            return maxi- mini;
        }
        else{
            return max(secondMax-mini, maxi-secondMini);
        }
    }
};