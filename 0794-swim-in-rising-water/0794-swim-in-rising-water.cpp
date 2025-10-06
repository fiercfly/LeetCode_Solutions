class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;++i) parent[i]=i;
    }
    int find(int x) {
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int xr=find(x), yr=find(y);
        if(xr!=yr) {
            if(rank[xr]<rank[yr]) parent[xr]=yr;
            else if(rank[xr]>rank[yr]) parent[yr]=xr;
            else {
                parent[yr]=xr;
                ++rank[xr];
            }
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();
        if(n == 1){
            return grid[0][0];
        }
        vector<pair<int, pair<int,int>>> edges;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int id= i*n +j;
                if(i+1 < n)edges.push_back({max(grid[i][j] , grid[i+1][j] ), {id, id+n}});
                if(j+1 < n)edges.push_back({max(grid[i][j] , grid[i][j+1] ), {id, id+1}});
            }
        }

        sort(edges.begin(), edges.end());
        DSU ds(n*n);
        for(auto & e: edges){
            ds.unite(e.second.first, e.second.second);
            if(ds.find(0) == ds.find(n*n-1)) return e.first;
        }

        return -1;
    }
};