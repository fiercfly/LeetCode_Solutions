class Solution {
public:
    void reverseString(vector<char>& s) {
        solve(s,0);
    }
    void solve(vector<char>& s, int indx){
        if(indx == s.size()){
            return;
        }
        char c= s[indx];
        indx++;
        solve(s,indx);
        s[s.size()-indx]=c;
        indx--;
    }
};