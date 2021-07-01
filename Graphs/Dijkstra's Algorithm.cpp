const int N=2e5+5;

vector<pair<int,int>>adj[N];
vector<int>dis(N,LLONG_MAX),vis(N,0);

void dijkstra(int s){
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >q;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]:adj[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
