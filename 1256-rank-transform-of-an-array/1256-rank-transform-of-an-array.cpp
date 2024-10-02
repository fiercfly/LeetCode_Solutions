class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& a) {
        std::unordered_map<int,int> mp;
        std::vector<int> b=a;
        std::sort(b.begin(),b.end());
        b.erase(std::unique(b.begin(),b.end()),b.end());
        for(int i=0;i<b.size();i++) {
            mp[b[i]]=i+1;
        }
        for(int i=0;i<a.size();i++) {
            a[i]=mp[a[i]];
        }
        return a;
    }
};
