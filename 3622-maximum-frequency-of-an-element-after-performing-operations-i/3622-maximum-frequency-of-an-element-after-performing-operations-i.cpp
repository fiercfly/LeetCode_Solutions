class Solution{
public:
	int maxFrequency(vector<int>&nums,int k,int ops){
        //mexi no
		int maxNum= *max_element(nums.begin(),nums.end());
		int sz=maxNum+ k+ 2;
		vector<int>freq(sz,0);
        
		for(int i=0; i<nums.size(); i++){
			freq[nums[i]]++;
		}
        
        //prefix array banao
		vector<int>pre(sz,0);
        
		pre[0]=freq[0];
		for(int i=1;i<sz;i++){
			pre[i]=pre[i-1]+freq[i];
		}

		int ans=0;
		for(int x=0;x<sz;x++){
            
			if(freq[x]==0 && ops==0){
                continue;
            }

			int l= max(0, x-k);
			int r= min(sz-1, x+k);
			int tr= pre[r]-(l>0 ? pre[l-1]: 0);
			int can=tr - freq[x];
			int ttl = freq[x]+min(ops,can);
            
			ans=max(ans,ttl);
		}

		return ans;
	}
};