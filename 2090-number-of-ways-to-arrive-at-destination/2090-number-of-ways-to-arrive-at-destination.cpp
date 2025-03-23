class Solution {
public:

    //Graph DP approach

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto &it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;//Minheap
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0]= 0;
        ways[0]= 1;
        pq.push({0,0});
        int mod= 1e9+7;
        while(!pq.empty()){
            long long dis= pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dis> dist[node]) continue;

            for(auto it: adj[node]){
                int nei = it.first;
                int wei = it.second;

                if((dis+ wei) < dist[nei]){
                    dist[nei] = dis+ wei;
                    pq.push({dist[nei], nei});
                    ways[nei] = ways[node];
                }
                else if(dis+ wei == dist[nei]){
                    ways[nei] = (ways[node]+ ways[nei])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};