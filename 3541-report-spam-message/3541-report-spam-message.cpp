class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> mp(bannedWords.begin(), bannedWords.end());
        int cnt= 0;
        for(string c: message){
            if(mp.count(c) && ++cnt ==2){
                return true;
            }
        }
        return false;
    }
};