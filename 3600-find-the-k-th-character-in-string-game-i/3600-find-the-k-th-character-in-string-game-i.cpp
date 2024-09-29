class Solution {
public:
    char kthCharacter(int k) {
        string a="a";
        while(a.length()<k){
            string b="";
            for(char c:a){
                char d=(c=='z')?'a':(c+1);
                b+=d;
            }
            a+=b;
        }
        return a[k-1];
    }
}; 