class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left= 0;
        int maxi= 0;
        int curr= 0;
        for(int i=0; i<k; i++){
            curr+= cardPoints[i];
        }
        maxi= curr;
        //left k end se remove karo and right end se add karo
        for(int i=0; i<k; i++){
            curr-= cardPoints[k-1-i];
            curr+= cardPoints[cardPoints.size()-1-i];
            maxi= max(curr, maxi);
        }
        return maxi;
    }
};