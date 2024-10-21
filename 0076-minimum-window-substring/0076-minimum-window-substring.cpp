class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        if(s.length()<t.length()){
            return "";
        }

        //value map is there..
        for(char c: t){
            mp[c]++;
        }

        //since we have to find all the characters in t in our s so...
        int remain= t.length();


        int wdw[2]= {0,INT_MAX};

        int st= 0;
        for(int end= 0; end<s.length(); end++){
            char c= s[end];
            //if we get the char in our map means there is a possibility that t can be in s
            if(mp.find(c)!= mp.end() && mp[c]>0){
                remain--;
            }

            mp[c]--;

            //if remain=0 means all the characters of t is in window so do calc..

            if(remain== 0){
                while(true){
                    char c= s[st];
                    if(mp.find(c)!= mp.end() && mp[c]== 0){
                        //tht char is form our t and has single occurence so cant remove
                        break;
                    }

                    mp[c]++;
                    st++;
                }

                if(end- st < wdw[1]- wdw[0]){
                    wdw[0]= st;
                    wdw[1]= end;
                }

                //start shrinking the window

                mp[s[st]]++;
                remain++;
                st++;
            }
        }
        return wdw[1]>= s.length()? "": s.substr(wdw[0], wdw[1]+1- wdw[0]);
    }
};