class Solution {
public:
    int ans= 0;
    void prov(vector<vector<int>>& isConnected,int cur, vector<int> &vis){
        vis[cur]= 1;

        for(int i=0;i<isConnected[cur].size(); i++){
            if(isConnected[cur][i]==1 && !vis[i]){
                prov(isConnected, i, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(), 0);
        for(int i=0; i<isConnected.size(); i++){
            if(!vis[i]){
                ans++;
                prov(isConnected, i, vis);
            }
        }

        return ans;

    }
};