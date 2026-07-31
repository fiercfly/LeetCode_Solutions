class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for(auto i:word){
            mp[i]++;
        }
        vector<int> vct;
        for(auto i:mp){
            vct.push_back(i.second);
        }
        sort(vct.rbegin(), vct.rend());

     //8 buttons can be possible at a time
     int ans=0;
    
        int tap= 1;
        int cnt= 1;
        for(auto i: vct){
            if(cnt> 8){
                cnt= 1;
                tap++;
            }
            ans+= tap*i;
            cnt++;

        }

        return ans;
    }
};