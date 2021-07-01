const int N=2e5+5;

vector<pair<int,int>>adj[N+1];
vector<int>d(N,INT_MAX);

void dijkstra(int s){
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >q;
    d[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int v= q.top().second;
        q.pop();
        for(auto x:adj[v]){
            int dist= x.second;
            int u= x.first;
            if(d[u]> d[v]+dist){
                d[u]=d[v]+dist;
                q.push({d[u],u});
            }
        }
    }
}
