class Solution {
public:
    bool isPal(string s, int left, int right){
        while(left<= right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void rec(string s, vector<vector<string>> &ans, vector<string> &vct, int ind){
        if(ind >= s.length()){
            ans.push_back(vct);
            return;
        }

        for(int k=ind; k<s.length(); k++){
            if(isPal(s, ind, k)){
                vct.push_back(s.substr(ind, k-ind+1));
                rec(s, ans, vct, k+1);
                vct.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vct;

        rec(s, ans, vct, 0);

        return ans;
    }
};