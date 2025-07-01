class Solution{
public:
    int possibleStringCount(string w){
        int ans= 1;
        int n= w.length();
        for(int i=0;i<n;){
            char curr= w[i];
            int j=i;
            while(j<n && w[j]==curr){ 
                j++;
            }
            int len= j-i;
            if(len>1){
                ans+=(len-1);
            }
            i=j;
        }
        return ans;
    }
};