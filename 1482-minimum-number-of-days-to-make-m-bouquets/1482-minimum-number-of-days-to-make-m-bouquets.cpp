class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        // long long x= m;
        // x= x*k;
        // if(x > bloomDay.size())return -1;
        long low= 0;
        long high= *max_element(bloomDay.begin(), bloomDay.end());
        int ans= -1;
        while(low<= high){
            int mid= low+(high-low)/2;
            int cnt= 0;
            int ttlBoq= 0;
            for(int i=0; i<bloomDay.size(); i++){
                if(bloomDay[i]<=mid){
                    cnt++;
                }else{
                    cnt= 0;
                }

                if(cnt >= k){
                    ttlBoq++;
                    cnt= 0;
                }
            }
            if(ttlBoq>= m){
                ans= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
};


