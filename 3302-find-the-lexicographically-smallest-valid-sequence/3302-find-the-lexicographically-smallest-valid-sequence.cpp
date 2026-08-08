class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int> ans;
        int n= word1.size();
        int m= word2.size();

        int r= m-1;
        int c= 0;

        vector<int> rig(n);
        for(int i=n-1; i>=0; i--){
            rig[i] = c;
            if(r>= 0 && word1[i] == word2[r]){
                r--;
                c++;
            }
        }

        bool chang= false;
        int j= 0;

        for(int i=0; i<n &&  j<m; i++){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!chang && rig[i] >= m-1-j){
                ans.push_back(i);
                j++;
                chang= true;
            }
        }

        if(j == m){
            return ans;
        }

        return {};
    }
};