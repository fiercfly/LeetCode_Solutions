class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int maxi= 0;
        int sum= 0;
        for(int i=0; i<customers.size(); i++){
            int smax= 0;
            if(grumpy[i] == 0){
                sum+= customers[i];
            }
            for(int j= i; j<i+minutes && j<customers.size(); j++){
                if(grumpy[j] == 1){
                    smax+= customers[j];

                }
            }
            if(maxi<smax){
                maxi= smax;
            }
        }
        return sum+maxi;
    }
};