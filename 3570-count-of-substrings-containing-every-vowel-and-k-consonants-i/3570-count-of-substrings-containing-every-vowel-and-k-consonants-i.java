import java.util.HashSet;
import java.util.Set;

class Solution {
    public int countOfSubstrings(String str, int k) {
        int ans = 0;
        int n= str.length();
        for (int i= 0; i < n; i++) {
            Set<Character> hs= new HashSet<>();
            int vc= 0;
            for (int j= i; j< n;j++){
                char ch= str.charAt(j);
               if(ch=='a' ||ch=='e' || ch=='i'|| ch=='o'|| ch=='u'){
                    hs.add(str.charAt(j));
                    vc++;
                }
                int cc=(j-i+1)-vc;

                if(cc> k){
                    break;
                }
                if(hs.size()== 5 &&cc== k){
                    ans++;
                }
            }
        }
        return ans;
    }
}