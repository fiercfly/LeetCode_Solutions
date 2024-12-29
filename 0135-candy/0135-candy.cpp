class Solution {
public:
    int candy(vector<int>& ratings) {
        int maxCandies= 0;
        
        vector<int> candy(ratings.size(), 1);

        // candy[0]= 1;

        for(int i=1; i<ratings.size(); i++){
            if(ratings[i-1]<ratings[i]){
                candy[i]= candy[i-1]+1;
            }
        }

        for(int j=ratings.size()-2; j>= 0; j--){
            if(ratings[j+1]<ratings[j]){
                candy[j]=max(candy[j], candy[j+1]+1);
            }
        }

        for(int i: candy){
            maxCandies+= i;
        }

        return maxCandies;
    }
};