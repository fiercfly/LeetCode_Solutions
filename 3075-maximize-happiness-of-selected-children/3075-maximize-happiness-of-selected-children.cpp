class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long happinessValue = 0;
        int n= happiness.size();
        int happinessDec= 0;
        sort(happiness.begin(), happiness.end());
        for(int i=n-1; i>n-1-k; i--){
            happinessValue += (happiness[i]-happinessDec>0)? happiness[i]-happinessDec: 0;
            happinessDec++;
        }
        return happinessValue;
    }
};



// 2 -> minimum number
