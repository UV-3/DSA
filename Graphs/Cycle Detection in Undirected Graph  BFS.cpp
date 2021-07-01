// LOGIC-> if in the adjacency list of a node we encounter a node which is already
// visited and is not the parent then cycle exists
const int N=2e5+5;

vector<bool>vis(N,false);
vector<int>adj[N];

bool bfs(int s){
    queue<pair<int,int>>q;
    vis[s]=true;
    q.push({s,-1});
    while(!q.empty()){
        int v=q.front().first;
        int par= q.front().second;
        q.pop();
        for(auto u:adj[v]){
            if(!vis[u]){
                vis[u]=true;
                q.push({u,v});
            }
            else if( u!=par){
                return true;
            }
        }
    }
    return false;
}

bool check(int n){
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(bfs(i)){
                return true;
            }
        }
    }
    return false;
}
