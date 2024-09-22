class Solution {
public:
    long long validSubstringCount(string w1, string w2) {
        if(w2.size()>w1.size()){
            return 0;
        }
        int n2= w2.size();
        int n= w1.size();
        
        unordered_map<char, int> mp2;
        for(char c: w2){
            mp2[c]++;
        }
        unordered_map<char, int> mp;
        int rqrd= mp2.size();
        int lft= 0;
        int mtc= 0;
        long long ans= 0;
        for(int i=0; i<n; i++){
            char c= w1[i];
            mp[c]++;
            if(mp2.count(c) && mp[c]== mp2[c])mtc++;
            while(mtc == rqrd){
                ans+= (n-i);
                char temp= w1[lft];
                mp[temp]--;
                if(mp2.count(temp) && mp[temp]< mp2[temp]){
                    mtc--;
                }
                lft++;
            }
        }
        return ans;
        
        
    }
};