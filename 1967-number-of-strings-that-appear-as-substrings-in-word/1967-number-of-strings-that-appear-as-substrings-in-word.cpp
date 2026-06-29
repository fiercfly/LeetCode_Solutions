class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int pat= 0;
        for(string pattern: patterns){
            if(word.find(pattern) != string::npos){
                pat++;
            }
        }
        return pat;
    }
};