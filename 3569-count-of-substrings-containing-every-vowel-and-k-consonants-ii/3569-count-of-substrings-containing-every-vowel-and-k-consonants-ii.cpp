class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int> vow = 
        {
            {'a', 0},
            {'e', 0},
            {'i', 0},
            {'o', 0},
            {'u', 0}
        };
        int v = 0, c = 0, begin = 0, end = 0, nt = -1;
        int n = word.size();
        long long res = 0;
        
        while(end < n || (v == 5 && c >= k)) {
            if(v < 5 || c < k) {
                char curr = word[end];
                if(vow.find(curr) != vow.end()) {
                    vow[curr]++;
                    if(vow[curr] == 1) v++;
                } else c++;
                end++;
            } else {
                char curr = word[begin];
                if(vow.find(curr) != vow.end()) {
                    vow[curr]--;
                    if(vow[curr] == 0) v--;
                } else c--;
                begin++;
            }
            if(c == k && v == 5) {
                if(nt < end) {
                    nt = end;
                    while(nt < n && vow.find(word[nt]) != vow.end()) nt++; 
                }
                res += nt-end+1;
            }
        }
        return res;
    }
};