  vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int>dis(V,1e8);
        dis[S]=0;
        for(int i=0;i<V;i++){
            for(auto it:adj){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                dis[v]=min(dis[v],dis[u]+w);
            }
        }
        return dis;
    }
