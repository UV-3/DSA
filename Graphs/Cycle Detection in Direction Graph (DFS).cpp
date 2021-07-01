const int N=2e5+5;

vector<int>adj[N];
vector<bool>vis(N,false);
vector<bool>dfsvis(N,false);
// basic is if for a node both before going on that node if both vis and dfsvis are true then there is a cycle
bool dfs(int v){
    vis[v]=true;
    dfsvis[v]=true;
    for(int u:adj[v]){
        if(!vis[u]){
            if(dfs(u)){
                return true;
            }
        }
        else if(dfsvis[u]){
            return true;
        }
    }
    dfsvis[v]=false;
    return false;
}
bool check(int n){
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i))return true;
        }
    }
    return true;
}
