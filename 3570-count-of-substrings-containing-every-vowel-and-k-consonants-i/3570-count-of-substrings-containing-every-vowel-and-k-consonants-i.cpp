class Solution {
public:
    int countOfSubstrings(string w,int k){
        unordered_set<char> mp= {'a', 'e', 'i', 'o', 'u'};
        int ans= 0;
        int n= w.length();

        for(int i=0; i<n; i++){
            unordered_set<char> f;
            int cnt= 0;
            for(int j=i; j<n; j++){
                if(mp.count(w[j])){
                    f.insert(w[j]);
                }
                else{
                    cnt++;
                }
                if(cnt>k){
                    break;
                }
                if(f.size()==5 && cnt== k){
                    ans++;
                }
            }
        }
    return ans;
    }

};
