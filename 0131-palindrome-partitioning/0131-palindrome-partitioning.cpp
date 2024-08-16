class Solution {
public:
    bool isPal(string s, int start, int end) {
        while (start <= end) {
        if (s[start++] != s[end--])
            return false;
        }
        return true;
    }
    void generate(vector<vector<string>> &ans, string s, int ind, vector<string> &path){
        if(ind>= s.length()){
            ans.push_back(path);
            return;
        }

        for(int i=ind; i<s.length(); i++){
            if(isPal(s, ind, i)){
                path.push_back(s.substr(ind, i-ind+1));
                generate(ans,s, i+1, path);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        generate(ans, s, 0, path);
        return ans;
    }
};