class Solution {
public:
    bool psbl(long long t,int mountainHeight,vector<int>& worker){
        long long ttl= 0;
            for(auto time: worker){
                long long l=0;
                long long r= mountainHeight;
                while(l<r){
                    long long mid= (l+r+1)/2;
                    if(time*mid*(mid+1)/2 <= t){
                        l= mid;
                    }
                    else{
                        r= mid-1;
                    }
                }
                ttl+= l;
                if(ttl>= mountainHeight){
                    return true;
                }
            }
        if(ttl>= mountainHeight){
           return true;
        }
        else{
            return false;
        }
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long end= 1e18; 
        long long start=1;
        while(start<end){
            long long mid= (start+ end)/2;
            if(psbl(mid,mountainHeight,workerTimes)){
                end= mid;
            }
            else{
                start= mid+1;
            }
        }
        return start;
    }
};