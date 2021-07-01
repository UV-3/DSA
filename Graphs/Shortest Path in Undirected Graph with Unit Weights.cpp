const int N=2e5+5;

vector<int>d(N,INT_MAX);
vector<int>adj[N];

void bfs(int v){
    queue<int>q;
    q.push(v);
    d[v]=0;
    while(!q.empty()){
        int v= q.front();
        for(auto u:adj[v]){
            if(d[v]+1<d[u]){
                d[u]=d[v]+1;
                q.push(u);
            }
        }
    }
}
