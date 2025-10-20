class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans= 0;
        for(auto i: operations){
            if(i[0] == '+' || i[i.length()-1] == '+'){
                ans++;
            }
            else if(i[0] == '-' || i[i.length()-1]== '-'){
                ans--;
            }
        }
        return ans;
    }
};