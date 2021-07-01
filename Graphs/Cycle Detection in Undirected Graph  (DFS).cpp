// LOGIC-> if in the adjacency list of a node we encounter a node which is already
// visited and is not the parent then cycle exists
const int N=2e5+5;

vector<bool>vis(N,false);
vector<int>adj[N];

bool dfs(int v, int par){
    vis[v]=true;
    for(int u:adj[v]){
        if(!vis[u]){
            if(dfs(u,v)){
                return true;
            }
        }
        else if(u!=par){
            return true;
        }
    }
    return false;
}

bool check(int n){
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,-1)){
                return true;
            }
        }
    }
    return false;
}
